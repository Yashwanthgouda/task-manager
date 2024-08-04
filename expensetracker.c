#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_DESC_LENGTH 50
#define MAX_CAT_LENGTH 20
#define MAX_EXPENSES 100


typedef struct {
    char date[11];
    float amount;
    char category[MAX_CAT_LENGTH];
    char description[MAX_DESC_LENGTH];
} Expense;

void addExpense(Expense *expenses, int *numExpenses);
void viewSummary(Expense *expenses, int numExpenses);
void editExpense(Expense *expenses, int numExpenses);
void deleteExpense(Expense *expenses, int *numExpenses);
void setBudget(float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories);
void viewBudget(float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories);
void filterExpenses(Expense *expenses, int numExpenses);
void sortExpensesByDate(Expense *expenses, int numExpenses);
void sortExpensesByAmount(Expense *expenses, int numExpenses);
void expenseAnalytics(Expense *expenses, int numExpenses, float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories);

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float budgets[MAX_CAT_LENGTH];
    char categories[][MAX_CAT_LENGTH] = {"Food", "Utilities", "Transportation", "Entertainment"};
    int numCategories = sizeof(categories) / sizeof(categories[0]);
    char choice;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Summary\n");
        printf("3. Edit Expense\n");
        printf("4. Delete Expense\n");
        printf("5. Set Budget\n");
        printf("6. View Budget\n");
        printf("7. Filter Expenses\n");
        printf("8. Sort Expenses by Date\n");
        printf("9. Sort Expenses by Amount\n");
        printf("10. Expense Analytics\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addExpense(expenses, &numExpenses);
                break;
            case '2':
                viewSummary(expenses, numExpenses);
                break;
            case '3':
                editExpense(expenses, numExpenses);
                break;
            case '4':
                deleteExpense(expenses, &numExpenses);
                break;
            case '5':
                setBudget(budgets, categories, numCategories);
                break;
            case '6':
                viewBudget(budgets, categories, numCategories);
                break;
            case '7':
                filterExpenses(expenses, numExpenses);
                break;
            case '8':
                sortExpensesByDate(expenses, numExpenses);
                break;
            case '9':
                sortExpensesByAmount(expenses, numExpenses);
                break;
            case '10':
                expenseAnalytics(expenses, numExpenses, budgets, categories, numCategories);
                break;
            case '11':
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '11');

    return 0;
}

void addExpense(Expense *expenses, int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached. Cannot add more.\n");
        return;
    }

    Expense newExpense;
    printf("\nEnter expense details:\n");
    printf("Date (DD-MM-YYYY): ");
    scanf("%s", newExpense.date);

    while (getchar() != '\n');

    printf("Amount: ");
    scanf("%f", &newExpense.amount);

    while (getchar() != '\n');

    printf("Category: ");
    scanf("%s", newExpense.category);

    while (getchar() != '\n');

    printf("Description: ");
    scanf("%s", newExpense.description);

    while (getchar() != '\n');

    expenses[*numExpenses] = newExpense;
    (*numExpenses)++;
    printf("Expense added successfully.\n");
}


void viewSummary(Expense *expenses, int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\nExpense Summary:\n");
    printf("%-12s %-10s %-20s %s\n", "Date", "Amount", "Category", "Description");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-12s %-10.2f %-20s %s\n", expenses[i].date, expenses[i].amount, expenses[i].category, expenses[i].description);
    }
}

void editExpense(Expense *expenses, int numExpenses) {
    int index;
    printf("\nEnter index of expense to edit (1-%d): ", numExpenses);
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= numExpenses) {
        printf("Invalid expense index.\n");
        return;
    }

    printf("Enter new expense details:\n");
    printf("Date (YYYY-MM-DD): ");
    scanf("%s", expenses[index].date);
    printf("Amount: ");
    scanf("%f", &expenses[index].amount);
    printf("Category: ");
    scanf("%s", expenses[index].category);
    printf("Description: ");
    scanf("%s", expenses[index].description);

    printf("Expense updated successfully.\n");
}

void deleteExpense(Expense *expenses, int *numExpenses) {
    int index;
    printf("\nEnter index of expense to delete (1-%d): ", *numExpenses);
    scanf("%d", &index);
    index--;

    if (index < 0 || index >= *numExpenses) {
        printf("Invalid expense index.\n");
        return;
    }


    for (int i = index; i < *numExpenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    (*numExpenses)--;
    printf("Expense deleted successfully.\n");
}

void setBudget(float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories) {
    printf("\nSet Budget:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("Enter budget for %s: ", categories[i]);
        scanf("%f", &budgets[i]);
    }
    printf("Budgets set successfully.\n");
}

void viewBudget(float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories) {
    printf("\nBudget Summary:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%-20s %.2f\n", categories[i], budgets[i]);
    }
}

void filterExpenses(Expense *expenses, int numExpenses) {
    char category[MAX_CAT_LENGTH];
    printf("\nEnter category to filter (or 'all' to view all expenses): ");
    scanf("%s", category);

    if (strcmp(category, "all") == 0) {
        viewSummary(expenses, numExpenses);
    } else {
        printf("\nFiltered Expenses for Category '%s':\n", category);
        printf("%-12s %-10s %-20s %s\n", "Date", "Amount", "Category", "Description");
        for (int i = 0; i < numExpenses; i++) {
            if (strcmp(expenses[i].category, category) == 0) {
                printf("%-12s %-10.2f %-20s %s\n", expenses[i].date, expenses[i].amount, expenses[i].category, expenses[i].description);
            }
        }
    }
}

void sortExpensesByDate(Expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = 0; j < numExpenses - i - 1; j++) {
            if (strcmp(expenses[j].date, expenses[j + 1].date) > 0) {
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
    printf("\nExpenses sorted by date.\n");
}

void sortExpensesByAmount(Expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses - 1; i++) {
        for (int j = 0; j < numExpenses - i - 1; j++) {
            if (expenses[j].amount > expenses[j + 1].amount) {
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
    printf("\nExpenses sorted by amount.\n");
}

void expenseAnalytics(Expense *expenses, int numExpenses, float *budgets, char categories[][MAX_CAT_LENGTH], int numCategories) {
    float totalSpending = 0;
    float categorySpending[numCategories];
    int categoryCount[numCategories];
    for (int i = 0; i < numCategories; i++) {
        categorySpending[i] = 0;
        categoryCount[i] = 0;
    }

    for (int i = 0; i < numExpenses; i++) {
        totalSpending += expenses[i].amount;
        for (int j = 0; j < numCategories; j++) {
            if (strcmp(expenses[i].category, categories[j]) == 0) {
                categorySpending[j] += expenses[i].amount;
                categoryCount[j]++;
            }
        }
    }

    printf("\nExpense Analytics:\n");
    printf("Total Spending: $%.2f\n", totalSpending);
    printf("Average Spending per Category:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%-20s $%.2f\n", categories[i], categorySpending[i] / categoryCount[i]);
    }
    printf("Percentage of Budget Utilized:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%-20s %.2f%%\n", categories[i], (categorySpending[i] / budgets[i]) * 100);
    }
}
