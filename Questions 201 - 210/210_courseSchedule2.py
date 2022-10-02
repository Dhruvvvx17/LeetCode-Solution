from typing import List


def findOrder(numCourses: int, prerequisites: List[List[int]]) -> List[int]:

    prereq = {c: [] for c in range(numCourses)}

    for crs, pre in prerequisites:
        prereq[crs].append(pre)

    # a course/node has 3 possible states:
    # visited, visiting and unvisited

    output = []
    visit, cycle = set(), set()

    def dfs(crs):

        # cycle found
        if crs in cycle:
            return False

        # if already visited, don't have to visit again, its prereqs are already in output
        if crs in visit:
            return True

        # add to cycle to compare this for rest of the iterations
        cycle.add(crs)

        # check all the prereqs of current course
        for pre in prereq[crs]:
            if dfs(pre) == False:
                return False

        # remove from cycle, as it has been compared with other nodes
        cycle.remove(crs)

        # finally add to output
        visit.add(crs)
        output.append(crs)
        return True

    for c in range(numCourses):
        if dfs(c) == False:
            return []

    return output


if __name__ == "__main__":

    a = [[0, 5], [0, 4], [1, 0], [3, 1], [2, 3], [2, 0]]

    print(f"Order of taking up courses is: {findOrder(6, a)}")
