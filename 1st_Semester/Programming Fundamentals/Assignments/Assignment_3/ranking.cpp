#include <iostream>
using namespace std;


int main() {
    int num_students, rank_query, papers[num_students], service_hours[num_students];
    int current_rank = 1;
    int students_at_rank_query = 0;
    int i = 0;
    
    cin >> num_students >> rank_query;
    for (i = 0; i < num_students; ++i)
        cin >> papers[i] >> service_hours[i];

    for (i = 0; i < num_students - 1; ++i) {
        for (int j = 0; j < num_students - 1 - i; ++j) {
            if (papers[j] < papers[j + 1] || (papers[j] == papers[j + 1] && service_hours[j] < service_hours[j + 1])) {
                int temp_papers = papers[j];
                int temp_service_hours = service_hours[j];
        
                papers[j] = papers[j + 1];
                papers[j + 1] = temp_papers;
                service_hours[j] = service_hours[j + 1];
            
                service_hours[j + 1] = temp_service_hours;
            }
        }
    }

    
    i = 0;
    while (i < num_students) {
        int num_students_at_this_rank = 1;
        while (i + num_students_at_this_rank < num_students && papers[i] == papers[i + num_students_at_this_rank] && service_hours[i] == service_hours[i + num_students_at_this_rank])num_students_at_this_rank++;
        if (current_rank <= rank_query && rank_query < current_rank + num_students_at_this_rank)students_at_rank_query = num_students_at_this_rank;
        current_rank += num_students_at_this_rank;
        i += num_students_at_this_rank;
    }
    cout << students_at_rank_query << endl;
    return 0;
}
