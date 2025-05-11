import numpy as np
import matplotlib.pyplot as plt
import random

# 🎯 Target location
TARGET = np.array([7, 5])

# 🐦 Cuckoo Search Parameters
NUM_NESTS = 10
ITERATIONS = 30
PA = 0.25  # Probability of discovery
GRID_SIZE = 10

# 🎲 Initialize nests randomly on a 2D grid
nests = np.random.randint(0, GRID_SIZE, size=(NUM_NESTS, 2))

# 📏 Fitness function = Euclidean distance to target
def fitness(position):
    return np.linalg.norm(position - TARGET)

# 🌀 Lévy flight generator
def levy_flight(Lambda=1.5):
    u = np.random.normal(0, 1)
    v = np.random.normal(0, 1)
    step = u / (abs(v) ** (1 / Lambda))
    return int(np.round(step))

# 🔁 Main optimization loop
for it in range(ITERATIONS):
    for i in range(NUM_NESTS):
        # Generate a new solution by Lévy flight
        new_pos = nests[i] + np.array([levy_flight(), levy_flight()])
        new_pos = np.clip(new_pos, 0, GRID_SIZE - 1)

        # Replace randomly selected nest if better
        j = random.randint(0, NUM_NESTS - 1)
        if fitness(new_pos) < fitness(nests[j]):
            nests[j] = new_pos

    # 🗑 Abandon some nests and reinitialize
    for i in range(NUM_NESTS):
        if random.random() < PA:
            nests[i] = np.random.randint(0, GRID_SIZE, size=2)

# 🥇 Select best solution
best_nest = min(nests, key=fitness)
best_distance = fitness(best_nest)

# 🖼 Visual output
plt.figure(figsize=(6, 6))
plt.grid(True)
plt.xlim(0, GRID_SIZE)
plt.ylim(0, GRID_SIZE)
plt.scatter(*TARGET, color='red', marker='*', s=200, label='Target')
plt.scatter(nests[:, 0], nests[:, 1], color='blue', label='Final Nest Positions')
plt.scatter(*best_nest, color='green', marker='o', s=100, label='Best Nest')
plt.title(f"Best Nest: {best_nest.tolist()} | Distance to Target: {best_distance:.2f}")
plt.legend()
plt.show()
