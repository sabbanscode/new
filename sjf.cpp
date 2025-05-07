#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;       // Job Id
    int deadline;  // Deadline of job
    int profit;    // Profit if job is completed before or on deadline
};

// Comparator function to sort jobs by decreasing profit
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job> &jobs) {
    // Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<bool> slot(n, false);     // To track free time slots
    vector<char> result(n, ' ');     // To store result (scheduled jobs)
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        // Find a free slot from job.deadline-1 to 0
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = true;
                result[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output scheduled jobs
    cout << "Scheduled Jobs: ";
    for (char jobId : result) {
        if (jobId != ' ') cout << jobId << " ";
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    vector<Job> jobs = {
        {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    jobScheduling(jobs);
    return 0;
}