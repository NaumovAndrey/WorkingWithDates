#include "iostream"
#include "ctime"
#include "iomanip"

/*получение текущего времени*/
void time()
{
	/*получает текущее время как количество секунд, прошедших с начала эпохи (обычно 1 января 1970 года)*/
	std::time_t t = std::time(nullptr);

	/*создаем объект `local` типа `std::tm`, который будет использоваться для хранения временной информации, включая день, месяц, год, час, минуту и секунду..*/
	std::tm local;

	/* Функция `localtime_s` конвертирует время, представленное в переменной `t` типа `std::time_t`,
	в локальное время на основе структуры `std::tm` `local`. Теперь `local` содержит локальное время.*/
	localtime_s(&local, &t); 

	/*создаем буфер `buffer` типа `char` длиной 26 символов, куда будет сохранена конвертированная строка времени. 
	Функция `asctime_s` форматирует время, переданное в виде структуры `std::tm`, и сохраняет его в буфер. 
	Параметрами функции являются указатель на буфер, его размер и адрес структуры `local`.*/
	char buffer[26];
	asctime_s(buffer, sizeof(buffer), &local);

	/*вывод в консоль текущего времени*/
	std::cout << buffer << '\n';
}

void formatDate()
{
	std::time_t t = std::time(nullptr);
	std::tm local;
	localtime_s(&local, &t);

	/*Выводит текущий год месяц день ("%Y/%m/%d") %y в нижнем регистре выводит год (два знака)
	Часы всегда в верхнем регистре (%H:%M:%S) 
	%I для 12 часового отображения часов
	%A для вывода дня недели
	%B для словестного наименования месяца*/ 
	std::cout << std::put_time(&local, "%A %Y/%m(%B)/%d %H:%M:%S") << std::endl;
}


void enterDate()
{
	std::time_t t = std::time(nullptr);
	std::tm local;
	#ifdef _WIN32
	localtime_s(&local, &t);
	#else
	local = *std::localtime(&t);
	#endif

	char time_str[10];
	std::cin >> std::get_time(&local, "%H:%M");
	std::strftime(time_str, sizeof(time_str), "%H:%M", &local);

	std::cout<< "time: " << time_str << std::endl;
}



void lesson()
{
	//код с лекции устарел Ошибки в каждой строке!
	//то что сверху пытаюсь разобраться
}