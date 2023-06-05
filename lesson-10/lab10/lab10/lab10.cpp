#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

class NucleotideFrequencyCounter {
public:
    void CountNucleotides(const std::string& sequence, std::size_t start, std::size_t end) {
        for (std::size_t i = start; i < end; ++i) {
            char nucleotide = sequence[i];
            if (nucleotide == 'A') {
                Number_of_base('A');
            }
            else if (nucleotide == 'C') {
                Number_of_base('C');
            }
            else if (nucleotide == 'G') {
                Number_of_base('G');
            }
            else if (nucleotide == 'T') {
                Number_of_base('T');
            }
        }
    }

    std::size_t Show(char nucleotide) const {
        return number[nucleotide];
    }

private:
    std::atomic<std::size_t> number['T' + 1];
    std::mutex mutex;

    void Number_of_base(char nucleotide) {
        std::lock_guard<std::mutex> lock(mutex);
        ++number[nucleotide];
    }
};

int main() {
    std::string dnaSequence = "GACATGAAGGAACTACGCTAGCTAAGCTGGCCGTAAAGCTAGCTAGAAGCCGTTAAGCTACGAAAAAAA";
    int numThreads = 4;

    std::size_t sectionSize = dnaSequence.size() / numThreads;

    std::vector<std::thread> threads;
    NucleotideFrequencyCounter counter;

    for (int i = 0; i < numThreads; ++i) {
        std::size_t start = i * sectionSize;
        std::size_t end = (i == numThreads - 1) ? dnaSequence.size() : (start + sectionSize);

        threads.emplace_back(&NucleotideFrequencyCounter::CountNucleotides, &counter, std::ref(dnaSequence), start, end);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    std::cout << "Frequency of nucleotides:" << std::endl;
    std::cout << "A: " << counter.Show('A') << std::endl;
    std::cout << "C: " << counter.Show('C') << std::endl;
    std::cout << "G: " << counter.Show('G') << std::endl;
    std::cout << "T: " << counter.Show('T') << std::endl;

    return 0;
}