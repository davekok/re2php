#include "src/util/c99_stdint.h"
#include <algorithm>
#include <limits>

#include "src/conf/msg.h"
#include "src/ir/skeleton/skeleton.h"

namespace re2c
{

// 0 < DIST_MAX < DIST_ERROR <= std::numeric_limits<uint32_t>::max()
static const uint32_t DIST_ERROR = std::numeric_limits<uint32_t>::max();
static const uint32_t DIST_MAX = DIST_ERROR - 1;

// maximal distance to end node (assuming one iteration per loop)
// different from YYMAXFILL calculation
// in the way it handles loops and empty regexp
static void calc_dist(
	Skeleton &skel,
	std::vector<uint32_t> &dists,
	size_t i)
{
	const Node &node = skel.nodes[i];
	uint8_t &loop = skel.loops[i];
	uint32_t &dist = dists[i];

	if (dist != DIST_ERROR) {
		return;
	} else if (node.end()) {
		dist = 0;
	} else if (loop < 2) {
		local_inc _(loop);
		Node::arcs_t::const_iterator
			arc = node.arcs.begin(),
			end = node.arcs.end();
		for (; arc != end; ++arc) {
			const size_t j = arc->first;
			calc_dist(skel, dists, j);
			uint32_t &d = dists[j];
			if (d != DIST_ERROR) {
				if (dist == DIST_ERROR) {
					dist = d;
				} else {
					dist = std::max(dist, d);
				}
			}
		}
		dist = std::min(dist + 1, DIST_MAX);
	}
}

// calculate maximal path length, check overflow
uint32_t maxpath(Skeleton &skel)
{
	std::vector<uint32_t> dists(skel.nodes_count);
	calc_dist(skel, dists, 0);
	const uint32_t maxlen = dists[0];
	if (maxlen == DIST_MAX) {
		error("DFA path %sis too long", incond(skel.cond).c_str());
		exit(1);
	}
	return maxlen;
}

} // namespace re2c
