from sortedcontainers import SortedList
from typing import List
import collections

class Solution:
    def maxRectangleArea(self, xCoord: List[int], yCoord: List[int]) -> int:
        INF = 10 ** 20
        points = collections.defaultdict(list)
        for x, y in zip(xCoord, yCoord):
            points[x].append(y)
        for x in points.keys():
            points[x].sort()

        # points[x] contains all the y's on that line
        best = -1
        sl = SortedList()

        for x in sorted(points.keys()):
            remove = set()
            for y1, y2 in zip(points[x], points[x][1:]):
                index = sl.bisect_left((y1, INF))

                if index - 1 >= 0:
                    if sl[index - 1][0] == y1 and sl[index - 1][1] == y2:
                        px = sl[index - 1][2]
                        best = max(best, (y2 - y1) * (x - px))

            for y in points[x]:
                index = sl.bisect_left((y, -1))
                if index - 1 >= 0:
                    sindex = index - 1
                    while sindex >= 0:
                        if sl[sindex][0] <= y <= sl[sindex][1]:
                            remove.add(sl[sindex])
                        else:
                            break
                        sindex -= 1
                if index < len(sl):
                    sindex = index
                    if sl[sindex][0] <= y <= sl[sindex][1]:
                        remove.add(sl[sindex])

            for t in remove:
                sl.remove(t)

            for y1, y2 in zip(points[x], points[x][1:]):
                sl.add((y1, y2, x))

        return best
