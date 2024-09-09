class MovingAverage:
    def __init__(self):
        self.average = 0
        self.count = 0
        self.started = False

    def add(self, num):
        if self.started == False:
            self.average = num
            self.count = num
            self.started = True
        else:
            self.average = (self.count / (self.count + 1) * self.average) + (num / (self.count + 1))
            count = count + 1

        return self.average

    def get_average(self):
        return self.average

averages = [MovingAverage(), MovingAverage()]

samples_file = open("./samples/95MHz-center-100MHzCW", "rb")

sample_index = 0

while True:
    sample = samples_file.read(1)

    if len(sample) == 0:
        break

    sample_int = int.from_bytes(sample)

    print(sample_index % 2)

    sample_index = sample_index + 1

print(average)
