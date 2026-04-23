import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import os

class ExpenseTracker:
    def __init__(self, filename='expenses.csv', monthly_budget=5000):
        self.filename = filename
        self.monthly_budget = monthly_budget
        self.load_data()

    def load_data(self):
        if os.path.exists(self.filename):
            self.data = pd.read_csv(self.filename, parse_dates=['Date'])
        else:
            self.data = pd.DataFrame(columns=['Date', 'Amount', 'Category', 'Description'])
            self.data.to_csv(self.filename, index=False)

    def save_data(self):
        self.data.to_csv(self.filename, index=False)

    def add_expense(self, date, amount, category, description):
        if amount <= 0:
            print("Amount must be positive.")
            return
        new_expense = pd.DataFrame([{
            'Date': pd.to_datetime(date),
            'Amount': amount,
            'Category': category,
            'Description': description
        }])
        self.data = pd.concat([self.data, new_expense], ignore_index=True)
        self.save_data()
        print("Expense added successfully.")

    def monthly_summary(self):
        self.data['Month'] = self.data['Date'].dt.to_period('M')
        summary = self.data.groupby('Month')['Amount'].sum()
        print("\n Monthly Summary:")
        print(summary)
        over_budget = summary[summary > self.monthly_budget]
        if not over_budget.empty:
            print("\n Budget Alert: You've exceeded your limit in these months:")
            print(over_budget)

        # Visualization
        summary.plot(kind='bar', color='coral')
        plt.title("Monthly Spending Summary")
        plt.xlabel("Month")
        plt.ylabel("Total Spent")
        plt.tight_layout()
        plt.show()

    def category_breakdown(self):
        summary = self.data.groupby('Category')['Amount'].sum()
        print("\n Expense by Category:")
        print(summary)

        summary.plot(kind='pie', autopct='%1.1f%%')
        plt.title("Spending Distribution by Category")
        plt.ylabel("")
        plt.tight_layout()
        plt.show()

    def expense_distribution(self):
        sns.histplot(self.data['Amount'], bins=10, kde=True)
        plt.title("Distribution of Spending Amounts")
        plt.xlabel("Amount")
        plt.ylabel("Frequency")
        plt.tight_layout()
        plt.show()

    def run(self):
        print(" Welcome to Expense Tracker")
        while True:
            print("\nChoose an option:\n1. Add Expense\n2. Monthly Summary\n3. Category Breakdown\n4. Distribution Plot\n5. Exit")
            choice = input("Enter choice (1-5): ")
            if choice == '1':
                date = input("Date (YYYY-MM-DD): ")
                amount = float(input("Amount: "))
                category = input("Category: ")
                description = input("Description: ")
                self.add_expense(date, amount, category, description)
            elif choice == '2':
                self.monthly_summary()
            elif choice == '3':
                self.category_breakdown()
            elif choice == '4':
                self.expense_distribution()
            elif choice == '5':
                print(" Goodbye!")
                break
            else:
                print(" Invalid option.")

# Run the tracker
tracker = ExpenseTracker(monthly_budget=5000)
tracker.run()
