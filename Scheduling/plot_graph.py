import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
df = pd.read_csv("execution_times.csv")

# Plot the data
plt.figure(figsize=(10, 5))
plt.plot(df["num_activities"], df["time_sort_by_start"], label="Sort by Start Time", marker="o", linestyle="solid")
plt.plot(df["num_activities"], df["time_sort_by_finish"], label="Sort by Finish Time", marker="s", linestyle="solid")

# Labels and title
plt.xlabel("Number of Activities")
plt.ylabel("Execution Time (ms)")
plt.title("Activity Selection: Execution Time Comparison")

plt.yscale("log")
plt.legend()
plt.grid(True)

# Show the plot
plt.show()
