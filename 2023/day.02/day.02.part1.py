import sys

class Game():
    def __parse__(self,s):
        splits = s.split(":")
        self.id = int((splits[0].split())[1])
        _sets = splits[1].split(";")
        for s in _sets:
            s = s.strip()
            data = {'red':0, 'green':0, 'blue':0}
            cols = s.split(",")
            for col in cols:
                _n, _color = col.split()
                _n = int(_n)
                data[_color] = _n
            self.sets.append(data)
            

    def __init__(self, s):
        self.sets = []
        self.__parse__(s)
        self.ref = {'red':12, 'green':13, 'blue':14}

    def validate(self):
        for s in self.sets:
            if s['red'] > self.ref['red'] or s['green'] > self.ref['green'] or s['blue'] > self.ref['blue']:
                return False
        return True

sum_ids = 0
while True:
    line = sys.stdin.readline()
    if not line:
        break
    line = line.rstrip()
    if len(line) == 0:
        break
    g = Game(line)
    if g.validate():
        sum_ids += g.id
        print(g.id)

print(sum_ids)
