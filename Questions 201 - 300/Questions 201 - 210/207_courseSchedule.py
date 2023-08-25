from typing import List

def canFinish(numCourses: int, courses: List[List[int]]) -> bool:
    
    # create a adjacency list
    preMap = {i:[] for i in range(numCourses)}
    
    # populate adjacency list
    for course, prereq in courses:
        preMap[course].append(prereq)
    
    # set of courses that have been currently visited in the cycle
    visited = set()        
    
    # iterate over all possible courses as they could be disconnected
    for course in range(numCourses):
        if not(dfs(course, preMap, visited)):
            return False
    
    return True


def dfs(course, preMap, visited):

    # If already visited in current iteration then cycle exists
    if(course in visited):
        return False

    # If there exists no preReq then course can be completed
    if(preMap[course] == []):
        return True

    # add current course so as to not consider it in current iteration
    visited.add(course)

    # depth-first search for every preReq (recursively)
    for prereq in preMap[course]:
        if not(dfs(prereq, preMap, visited)):
            return False
    
    # remove current course as if code flow has reached this point the course and it's pre reqs can be completed.
    visited.remove(course)
    
    # As the preReqs can be completed the current course can also be completed, 
    # hence don't have to check it's prereqs anymore.
    preMap[course] = []
    return True

if __name__ == "__main__":
    n = int(input("Enter number of courses: "))

    courses = []
    for i in range(n):
        p = int(input(f"Enter prereq course for course {i} (-1 if none exist): "))
        if p != -1:
            courses.append([i,p])       

    if(canFinish(n, courses)):
        print("The set of courses can be completed")
    else:
        print("The set of courses cannot be completed")    