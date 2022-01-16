# Backtracking and DFS approach, check every possible (?) split of the IP address, 
# BACKTRACK to previous step when invalid is found
# add any valid IP to the res list

from typing import List

def restoreIpAddresses(s: str) -> List[str]:
    # define variable for dfs call
    ip_remaining = s
    num_parts = 0
    curr_ip = ""
    res = []

    # call dfs
    dfs(ip_remaining, num_parts, curr_ip, res)

    return res
    
    
def dfs(ip_remaining, num_parts, curr_ip, res):

    # invalid as ip can have only 4 parts
    if(num_parts > 4):
        return  #backtracking

    # valid ip
    if(num_parts==4 and not ip_remaining):
        curr_ip = curr_ip[:-1]    # to remove the last period 
        res.append(curr_ip)
        
    # ip in construction
    for i in range(1,len(ip_remaining)+1):
        # check if the pattern is '0' in which case add it to curr_ip
        # because '0' can be the only independent value, '0xx' is invalid
        # otherwise, check if the beginning is not 0 and the pattern is between 0 and 256
        # because valid values lie between 1 and 255
        # in either case increment num_parts and append the [:i] segment of ip_remaining to curr_ip
        # reduce the same [:i] from ip_remaining and continue the dfs
        if(ip_remaining[:i]=='0' or (ip_remaining[0]!='0' and 0<int(ip_remaining[:i])<256)):
            dfs(ip_remaining[i:], num_parts+1, curr_ip+ip_remaining[:i]+".", res)

if __name__ == "__main__":
    ip_addr = input("Enter a numeric string to find valid IP addresses: ")
    print(f"Valid IPs are: {restoreIpAddresses(ip_addr)}")