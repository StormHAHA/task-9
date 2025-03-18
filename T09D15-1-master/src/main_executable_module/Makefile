CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCES = main_executable_module.c ../data_libs/data_io.c ../data_libs/data_stat.c ../data_module/data_process.c ../yet_another_decision_module/decision.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = main_executable_module

# Директория для статической библиотеки
STATIC_LIB_DIR = ../data_libs
STATIC_LIB = $(STATIC_LIB_DIR)/data_stat.a

# Цель по умолчанию
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(EXECUTABLE)

# Правило для создания статической библиотеки
$(STATIC_LIB): $(STATIC_LIB_DIR)/data_stat.o
	ar rcs $(STATIC_LIB) $(STATIC_LIB_DIR)/data_stat.o

# Компиляция объектных файлов
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

# Цель для сборки исполнимого файла с подключением статической библиотеки
build_with_static: $(EXECUTABLE) $(STATIC_LIB)
	$(CC) $(CFLAGS) $(OBJECTS) $(STATIC_LIB) -o $(EXECUTABLE)

# Цель clean для удаления объектных файлов и исполнимого файла
clean:
	rm -f $(OBJECTS) $(EXECUTABLE) $(STATIC_LIB)

# Цель rebuild для полной пересборки
rebuild: clean all