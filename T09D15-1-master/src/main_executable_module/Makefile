CC = gcc
CFLAGS = -Wall -Wextra -Werror -fPIC
LDFLAGS = -Wl,-rpath,../data_module  # Учитываем MacOS rpath

SOURCES = main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main_executable_module

# Директории библиотек
STATIC_LIB_DIR = ../data_libs
STATIC_LIB = $(STATIC_LIB_DIR)/data_stat.a
DYNAMIC_LIB_DIR = ../data_module
DYNAMIC_LIB = $(DYNAMIC_LIB_DIR)/libdata_process.so  # Исправлено имя

# Цель по умолчанию
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Создание статической библиотеки
$(STATIC_LIB): $(STATIC_LIB_DIR)/data_stat.o
	ar rcs $(STATIC_LIB) $(STATIC_LIB_DIR)/data_stat.o

# Создание динамической библиотеки (исправлено имя)
$(DYNAMIC_LIB): ../data_module/data_process.o $(STATIC_LIB)
	$(CC) -shared -o $(DYNAMIC_LIB) ../data_module/data_process.o $(STATIC_LIB)

# Компиляция объектных файлов
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Сборка с динамической библиотекой
build_with_dynamic: $(EXECUTABLE) $(DYNAMIC_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) -L$(DYNAMIC_LIB_DIR) $(LDFLAGS) -ldata_process -o $(EXECUTABLE)

# Очистка
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(STATIC_LIB) $(DYNAMIC_LIB) \
	      ../data_module/*.o ../data_module/*.so
# Полная пересборка
rebuild: clean all
