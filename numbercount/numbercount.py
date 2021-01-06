print("input 5 decimals")
values = []
for i in range(5):
    values.append(float(input("demical #"+str(i+1)+": ")))
cnt = 0
for i in values:
    if i >= 10 and i <= 100:
        cnt += 1
print(cnt)
