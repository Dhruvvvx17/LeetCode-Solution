import re

def isMatch(self, s: str, p: str) -> bool:
        try:
            return re.match('^' + p + '$', s) != None
        except:
            return False