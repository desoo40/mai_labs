import pickle

pickle_name = 'city.pickle'

data = {}
data['Москва'] = [16, 27, 15, 22],
data['Санкт-Петербург'] = [11, 19, 29, 5],
data['Нососибирск'] = [2, 23, 3, 15],
data['Томск'] = [8, 9, 10, 7],
data['Верхний Волочок'] = [96, 5, 6, 74]
data

with open(pickle_name, 'wb') as f:
     pickle.dump(data, f)

with open(pickle_name, 'rb') as f:
     new_data = pickle.load(f)

print(new_data)

# Посмотрим внутрь файла
file = open(pickle_name,"r")
content=file.read()
print(content)
