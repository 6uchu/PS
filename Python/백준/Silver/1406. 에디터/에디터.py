import sys

st = list(sys.stdin.readline().strip())
bakd = []
m = int(sys.stdin.readline())

for i in range(m):
  l = sys.stdin.readline().strip().split()
  if l[0] == 'L' and st:
    bakd.append(st.pop())
  elif l[0] == 'D' and bakd:
    st.append(bakd.pop())
  elif l[0] == 'B' and st:
    st.pop()
  elif l[0] == 'P':
    st.append(l[1])

#st.extend(reversed(bakd))
st = st + bakd[::-1]

print(''.join(st))