from record import Record 
from linear_probing_hashtable import LinearProbingHashTable 
from double_hashing_hashtable import DoubleHashingHashTable 
 
def main(): 
     
    num_students = int(input("Enter the number of students: ")) 
     
    linear_probing_table = LinearProbingHashTable(num_students) 
    double_hashing_table = DoubleHashingHashTable(num_students) 
 
    for i in range(num_students): 
         
        name = input(f"Enter students {i + 1} name: ") 
         
        phone_number = input(f"Enter students {i + 1} phone number: ") 
        record = Record(name, phone_number) 
 
        linear_probing_table.insert(record) 
        double_hashing_table.insert(record) 
 
    names_to_find = input("Enter names to find (separated by comma): ").split(',') 
     
    for name in names_to_find: 
        print(f"Finding phone number for {name.strip()} using Linear Probing: 
{linear_probing_table.find(name.strip())}") 
        print(f"Finding phone number for {name.strip()} using Double Hashing: 
{double_hashing_table.find(name.strip())}") 
 
if __name__ == "__main__": 
    main() 
record.py 
class Record: 
    def __init__(self): 
        self.name = None 
        self.number = None 
     
    def set_name(self, na): 
        self.name = na 
     
    def set_number(self, num): 
        self.number = num 
     
    def get_number(self): 
        return self.number 
     
    def get_name(self): 
        return self.name 
     
    def __str__(self): 
        return "Name: {} Number: {}".format(self.name, self.number) 
 
linear_probing_hashtable.py 
from record import Record 
 
class LinearProbingHashTable: 
    def __init__(self, size): 
        self.size = size 
        self.table = [None] * size 
 
    def hash(self, key): 
        return key % self.size 
 
    def insert(self, record): 
        index = self.hash(record.name) 
         
        while self.table[index] is not None: 
            index = (index + 1) % self.size 
        self.table[index] = record 
 
 
    def find(self, key): 
        index = self.hash(key) 
     
        while self.table[index] is not None: 
            if self.table[index].name == key: 
                return self.table[index].phone_number 
            index = (index + 1) % self.size 
        return "Not found" 
 
double_hashing_hashtable.py 
from record import Record 
 
class DoubleHashingHashTable: 
    def __init__(self, size): 
        self.size = size 
        self.table = [None] * size 
 
    def hash(self, key): 
        return hash(key) % self.size 
 
    def second_hash(self, key): 
        # Choose a second hash function 
        # For simplicity, using a simple second hash function 
        return 7 - (hash(key) % 7) 
 
    def insert(self, record): 
        index = self.hash(record.name) 
        step = self.second_hash(record.name) 
        while self.table[index] is not None: 
            index = (index + step) % self.size 
        self.table[index] = record 
 
    def find(self, key): 
        index = self.hash(key) 
        step = self.second_hash(key) 
        while self.table[index] is not None: 
            if self.table[index].name == key: 
                return self.table[index].phone_number 
            index = (index + step) % self.size 
        return "Not found"