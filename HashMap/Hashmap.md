# Hash Map

## Index

### Creation

Store data in random order
```cpp
unordered_map<int, int> m;
```

Store data in key's ascending order
```cpp
map<int, int> m;
```

### Insertion, Updation and Deletion
```cpp
m["a"] = 1;

//using  Pair
pair<string, int> p1 = {"b", 2};
m.insert(p1);

pair<string, int> p2("c", 3);
m.insert(p2);

pair<string, int> p3 = make_pair("d", 4);
m.insert(p3);

m["a"] = 5;

cout << m.size() << endl; // returns size of map

m.erase("b");   // Erase specified key value pair using key and decreases size by 1

```

### Traversee Map

```cpp
for(int x : m){
    cout << x.first << " " << x.second << endl;
}


//using iterator
unordered_map<string, int>::iterator it = m.begin();

while(it !=  m.end()){
    cout << it->first << " " << it->second << endl;
}

```

###

```cpp
cout << m.at["unknownEntry"] << endl; // out of bound exception
```

```cpp
cout << m["unknownEntry"] << endl; // Creates new entry and returns default=0 value
cout << m.at["unknownEntry"] << endl; // entry already created returns value=0
```

### Find if Present
```cpp
cout << m.count("Key") << endl; // Returns 0 if key not present else returns 1
```

