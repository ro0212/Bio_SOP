import matplotlib.pyplot as plt

def read_nucleotide_data(file_path):
    nucleotides_data = {'A': [], 'C': [], 'G': [], 'T': []}

    with open(file_path, 'r') as file:
        current_nucleotide = None
        for line in file:
            line = line.strip()
            if line in ['A', 'C', 'G', 'T']:
                current_nucleotide = line
            elif current_nucleotide:
                nucleotides_data[current_nucleotide].extend(map(int, line.split()))

    return nucleotides_data


def plot_nucleotide_occurrence(nucleotides_data):
    positions = list(range(1, 31))  # Positions from 1 to 30
    bar_width = 0.125  # Width of each bar

    plt.figure(figsize=(10, 6))

    # Plotting bars for each nucleotide separately
    for i, (nucleotide, frequencies) in enumerate(nucleotides_data.items()):
        plt.bar([pos + i * bar_width for pos in positions], frequencies[:30], bar_width, label=nucleotide)

    plt.xlabel('Position')
    plt.ylabel('Frequency')
    plt.title('Nucleotide Occurrence in Spacer Sequences')
    plt.xticks([pos + 1.5 * bar_width for pos in range(1, 31)], range(1, 31))
    plt.legend()
    plt.grid(True)
    plt.show()

# Example usage:
file_path = 'data.txt'  # Change this to your file path
nucleotides_data = read_nucleotide_data(file_path)

# Plotting bars for each nucleotide
plot_nucleotide_occurrence(nucleotides_data)
