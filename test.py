samples_file = open("./samples/95MHz-center-100MHzCW", "rb")

started = False

average = 0
count = 0

while True:
    sample = samples_file.read(1)

    if len(sample) == 0:
        break

    sample_int = int.from_bytes(sample)

    if started == False:
        started = True
        average = sample_int
        count = 1
    else:
        average = (count / (count + 1) * average) + (sample_int / (count + 1))
        count = count + 1

print(average)
