//////////////////////////////////////////////////////////////////////////////// 
// 
// step4.cpp - Приемы работы
// 
// 1. Работа с БД                           - DrawTxtDB
// 2. Процессы Cursor и Placement           - DrawRectCallBack, DrawRectNULL - <step4_1.cpp> 
// 3. Ввод длинного целого
// 4. Выбор имени файла                     - SelectFileName
// 5. Записать слайд                        - WriteSlideStep
// 6. Отрисовать слайд                      - TestShowDialog                 - <slidefrm.cpp> 
// 7. Пример с обработкой очереди сообщений - TaskAccess
// 8. Относительный путь файла              - WorkRelativePath
// 9. Работа с системными каталогами        - WorkSystemPath
// 
////////////////////////////////////////////////////////////////////////////////
#include <vcl.h>
#pragma hdrstop

#include <tchar.h>

#include <stdio.h>

#include <libtool.h>

#include "libdb.h"

#include "step4.rh"


//------------------------------------------------------------------------------
// в Win32 линкуется SDK/lib/kAPI2D5bc.lib
// в x64 линкуется SDK/lib64/kAPI2D5bc.a
// ---
#pragma comment(lib, "kAPI2D5bc")

//-------------------------------------------------------------------------------
// Задать идентификатор ресурсов
// ---
extern "C" unsigned int far __export __stdcall LIBRARYID()
{
  return IDR_LIBID;
}


//-------------------------------------------------------------------------------
// Описания используемых функций
// ---
void DrawTxtDB();
void DrawRectCallBack();
void SelectFileName();
void DrawRectNULL();
void WriteSlideStep();
void TaskAccess();
void WorkRelativePath();
void WorkSystemPath();
void TestShowDialog();


extern "C" void far __export __stdcall  LIBRARYENTRY( UINT comm )
{
  switch ( comm )
  {
    // Работа с БД
    case 1 :
      DrawTxtDB();
      break;
 
    // Ввод длинного целого
    case 3 :
    {
      long index;
      // Ввод длинного целого
			if ( ReadLongT( _T("Ввести индекс"), // Строка приглашения
											10000,           // Предлагаемое значение по умолчанию
										 -100000l,        // Интервал возможных значений
											100000l,
											&index ) )       // Результат ввода
			{
				TCHAR buf[255];
				_stprintf( buf, _T("Индекс = %ld"), index );
				MessageT( buf );
			}
			else
				MessageT( _T("Отказ") );
			break;
		}

		// Выбор имени файла
		case 4 :
			SelectFileName();
			break;

		// Отрисовать слайд( описание в файле <step4_2.cpp> )
		case 7 :
			TestShowDialog();
			break;

		// Работа с относительными путями файлов
		case 9 :
			WorkRelativePath();
			break;

		// Работа с системными каталогами
		case 10 :
			WorkSystemPath();
			break;

		default:
		{
			if ( ksGetCurrentDocument( 1 ) ) // Получить активный 2D документ
			{
				switch ( comm )
				{
					// Процессы Cursor и Placement( описание в файле <step4_1.cpp> )
					case 2 :
					{
						// Запрос к пользователю, возвращает резельтат запроса ( 1 - да, 0 - нет, -1 - отмена  )
						int res = YesNoT( _T("Вызывать функцию CallBack?") );
						if ( res == 1 )
							DrawRectCallBack();
						else
							if ( res == 0 )
								DrawRectNULL();
							else
								MessageT( _T("Отмена") );
						break;
					}

					// Записать слайд
					case 6 :
						WriteSlideStep();
						break;

					// Доступ к задаче
					case 8 :
						TaskAccess();
						break;
				}
			}
			else
				MessageT( _T("Документ не активизирован или\nне является листом/фрагментом") );
		}
	}
}


//--------------------------------------------------------------------------------
// Работа с текстовой базой данных
// Данные сформированы в виде таблицы обнородных строк, колонки
// разделены  пробелами или запятыми
// ---
void DrawTxtDB()
{
	TCHAR fileName[255];
	// Интерактивный выбор файла, возвращает реальную длину имени файла, либо 0 вслучае отказа
	if ( ksChoiceFileT( _T("*.loa"),  // Предопределенный тип файла
										 // Фильтр поиска ( если не задан, то формируется автоматически )
										 _T("Базы данных( *.loa )|*.loa|Все файлы ( *.* )|*.*|"),
										 fileName, // Результат выбора
										 255,      // Длина строки выбора
										 0 ) )     // Окно предварительного просмотра ( - 1 - с подключением окна
															 // предварительного просмотра, 0 - без подключения окна
															 // предварительного просмотра )
	{
		// Cоздать объект, обслуживающий базу данных ( ODBC_DB - интерфейс ODBC, TXT_DB - текстовые файлы )
		reference rDataBase = CreateDBT( _T("TXT_DB") );

		// Cвязать объект базы с определенной базой данных, для текстового файла - имя файла
		if ( ConnectDBT( rDataBase, fileName ) )
		{
			// Пример для считывания всех записей из базы в структуру record

			// Cоздать отношение - буфер для считывания информации из таблицы
			// В нашем случае это два double и один int, при этом не важно сколько колонок
			// В базе, важно чтобы их было >= описанных в Relation
			reference rRelation = Relation( rDataBase );
				RDoubleT( _T("A") ); // Имена даются ключевым колонкам,
				RDoubleT( _T("B") ); // По ним в дальнейшем формируются условия выборки
				RIntT( _T("") );
			EndRelation();

			// Установить запрос - отношение связывается с базой( указываем какие колонки
			// базы связать с переменными буфера )
			DoStatementT( rDataBase, rRelation, _T("1 2 3") ); // Колонка A - 1, B - 2, оставшаяся колонка - 3

			/*
			// Пример для считывания только второй строки
			Condition( rDataBase, rRelation, "Index1000 = 2" ); // Считать строку 2
			*/

			/*
			// Пример для считывания с условиями "A = 100 || A = 120"
			// Определим запрос ( считать все строки у которых в колонке A лежит 100 или 120
			Condition( rDataBase, rRelation, "A = 100 || A = 120" );
			*/

			TCHAR buf[255];

			// Структура для считывания информации из базы
			struct {
				double a, b;
				short int c;
			} record;

			// Считывание данных из базы
			int repeat = 1;
			while ( repeat )
			{
        // Считать очередную порцию информации и положть в структуру record
        repeat = ReadRecord( rDataBase, rRelation, &record );
        if ( repeat )
        {
					_stprintf( buf, _T("a = %4.1f, b = %4.1f, c = %i"), record.a, record.b, record.c );
					MessageT( buf );
        }
      }
			MessageT( _T("Конец выборки") );

      // Пример для считывания строк из базы
      // Создать еще одно отношения для считывания поля в виде строки
      // У базы данных отношений может быть сколько угодно
      rRelation = Relation( rDataBase );
				RCharT( _T("L"), 20, 0 ); // Строка из 20 символов
      EndRelation();

      // ( если связываются последовательно все колонки
      // текстовой базы, то допускается посылать пустую строку -"" )
			DoStatementT( rDataBase, rRelation, _T("4") ); // Строку буфера связать с 4 колонкой базы
 
      // Считывание данных из базы
      repeat = 1;
			while ( repeat )
      {
        // Считать очередную порцию информации и положть в buf
				repeat = ReadRecord( rDataBase, rRelation, buf );
        if ( repeat )
					MessageT( buf );
      }
			MessageT( _T("Конец выборки") );
    }
    // Удалить обьект, обслуживающий базу данных
    // рассоединение базы с файлом, удаление отношений произойдет автоматически
    DeleteDB( rDataBase );
  }
}


//-------------------------------------------------------------------------------
// Выбор имени файла 
// ---
void SelectFileName()
{
	TCHAR choice[10]; // Размерность 10 символов
  // Интерактивный выбор файла, возвращает реальную длину имени файла, либо 0 вслучае отказа
	int size = ksChoiceFileT( _T("*.cdw"), // Предопределенный тип файла
												 // Фильтр поиска ( если не задан, то формируется автоматически )
												 _T("Чертежи( *.cdw )|*.cdw|Фрагменты( *.frw )|*.frw|Все файлы ( *.* )|*.*|"),
												 choice, // Результат выбора
												 10, 1 );   // Длина строки выбора
	if ( size )
	{
		if ( size > 10 ) // Если длина более 10 символов
		{
			// Заводим новый буфер под имя файла
			TCHAR* newChoice = new TCHAR[ size+1 ];
			// Получить действительное имя файла, возвращает реальную длину имени файла
			size = GetRightFileNameT( newChoice, // Результирующее имя файла
															 size+1 );  // Длина строки выбора

			TCHAR buf[255];
			_stprintf( buf, _T("Размер строки\n%s\nбольше 10, реальный размер %i символов"), newChoice, size );
			MessageT( buf );

			delete[] newChoice;
		}
		else
			MessageT( choice );
	}
	else
		MessageT( _T("Отказ") );
}


//-------------------------------------------------------------------------------
// Пример с обработкой очереди сообщений
// ---
void  TaskAccess()
{
	EnableTaskAccess( 0 ); // Запретили доступ к задаче
	for ( int i = 0; i < 10000; i++ )
	{
		LineSeg( 10, 10 + i, 20, 10 + i, 1 );
		if ( !( i % 100 ) )
		{
			// Посылаем необрабатываемое сообщение своему приложению
			// для выполнения процесса в фоновом режиме
			PostThreadMessage( GetCurrentThreadId(), 0, 0, 0 );
			// Через каждые 100 отрезков обрабатываем очередь сообщений
			// При этом Windows получает возможность выполнить свои
			// действия, например переключиться на другую задачу
			PumpWaitingMessages();
		}
	}
	EnableTaskAccess( 1 ); // Разрешили доступ к задаче
}


//-------------------------------------------------------------------------------
// Записать слайд
// ---
void WriteSlideStep()
{
	TCHAR name[255];

	// Выберем файл для записи
	if ( ksSaveFileT( _T("*.rc"), NULL, NULL, name, 255, 0 ) )
	{
		// Структура параметров запроса к системе
		RequestInfoT info;
		memset( &info, 0, sizeof( info ) );

		// Строка или идентификатор меню состава команд
		info.commands = _T("Укажите точку привязки слайда");

		double x, y; // Точка привязки слайда - верхний левый угол габаритного прямоугольника слайда

		// Интерактивный ввод точки или комманды
		if ( CursorExT( &info,   // Указатель на структуру параметров запроса к системе
										&x,      // Координаты введенной точки
										&y,
										NULL, NULL ) ) // Указатель на структуру управления фантомом, определяющую тип	движения курсора
		{
			int slideId;
			// Ввод целого числа
			if ( ReadIntT( _T("Введите идентификатор слайда"), 100, 0, 32000, &slideId ) )
			{
				// Записать слайд
				if ( !WriteSlideT( name,    // Имя файла для записи
													 slideId, // Идентификатор слайда в файле ресурсов
													 x, y ) ) // Базовая точка
					ErrorT( _T("Группа селектирования пуста") );
				ClearGroup( 0 ); // Очистить группу объектов, если 0, то очистится группа селектирования
      }
    }
  }
}


//---------------------------------------------------------------------------------
// Работа с относительными путями файлов
// ---
void WorkRelativePath()
{
	TCHAR mainName[255];
	// Имя задающего файла
	if ( ksChoiceFileT( _T("*.*"), _T("Все файлы ( *.* )|*.*|"), mainName, 255, 1 ) )
	{
		TCHAR fileName[255];
		// Требуемый файл
		if ( ksChoiceFileT( _T("*.*"), _T("Все файлы ( *.* )|*.*|"), fileName, 255, 1 ) )
		{
			TCHAR resName[255];

			// Относительный путь
			ksGetRelativePathFromFullPathT( mainName,  // Полный путь к задающему файлу
																		 fileName,  // Полный путь к требуемому файлу
																		 resName,   // Результат - относительный путь к требуемому файлу( без общей с задающим файлом части пути )
																		 255 );     // Размер буффера

			WideString strMess( _T("Полный путь к задающему файлу:") );
			strMess += mainName;
			strMess += _T("\n");
			strMess += _T("Полный путь к требуемому файлу:");
			strMess += fileName;
			strMess += _T("\n");
			strMess += _T("Относительный путь к требуемому файлу:");
			strMess += resName;
			MessageW( strMess.c_bstr() );

			// Полный путь
			TCHAR fullName[255];
			ksGetFullPathFromRelativePathT( mainName,  // Полный путь к задающему файлу
                                     resName,   // Относительный путь к требуемому файлу( без общей с задающим файлом части пути )
                                     fullName,  // Результат - полный путь к требуемому файлу
                                     255 );     // Размер буффера
 
			strMess = _T("Полный путь к задающему файлу:");
      strMess += mainName;
			strMess += _T("\n");
			strMess += _T("Относительный путь к требуемому файлу:");
			strMess += resName;
			strMess += _T("\n");
			strMess += _T("Полный путь к требуемому файлу:");
			strMess += fullName;
			MessageT( strMess.c_bstr() );
    }
  }
}


//---------------------------------------------------------------------------------
// Работа с системными каталогами
// ---
void WorkSystemPath()
{
  // Сформировать полный путь к заданному файлу
	const TCHAR* catalogName[] = { _T("Каталог системных файлов"),
													 _T("Каталог библиотек"),
													 _T("Каталог временных файлов"),
													 _T("Каталог конфигурации"),
													 _T("INI-файл") };
  
  // Структура параметров запроса к системе
	RequestInfoT info;
  memset( &info, 0, sizeof( info ) );
  
	info.title    = _T("Каталоги файлов системы"); // Строка или идентификатор строки заголовка окна
	info.commands = _T("!Системные !Библиотеки !Временные !Конфигурация !INI-файл"); // Строка или идентификатор меню состава команд
	info.prompt   = _T("Выберите нужный каталог"); // Трока или идентификатор приглашения
 
  int comm = 1;
	static TCHAR *userFile = _T("user.ttt");
	TCHAR fileName[255];
  int typeCatalog;
  while ( comm > 0 )
  {
		comm = CommandWindowT( &info ); // Создание меню в диалоговом окне
    if ( comm > 0 )
    {
      switch ( comm )
      {
        case 1 : typeCatalog = sptSYSTEM_FILES; break; // Относительно каталога системных файлов
        case 2 : typeCatalog = sptLIBS_FILES;   break; // Относительно каталога файлов библиотек
        case 3 : typeCatalog = sptTEMP_FILES;   break; // Относительно каталога сохранения временных файлов
        case 4 : typeCatalog = sptCONFIG_FILES; break; // Относительно каталога сохранения конфигурации системы
        case 5 : typeCatalog = sptINI_FILE;     break; // Относительно полного имени INI-файла системы
      }

      // Полный путь
      ksGetFullPathFromSystemPathT( userFile,       // Относительный путь к файлу( без системного пути )
                                   fileName,       // Результат - полный путь к файлу
                                   255,            // Размер буффера
                                   typeCatalog ); // Путь установленного типа см. ksSystemPath
			WideString strMess( _T("Полный путь к файлу ") );
      strMess += userFile;
			strMess += _T("\n");
      strMess += catalogName[comm-1];
			strMess += _T("\n");
      strMess += fileName;
			MessageT( strMess.c_bstr() );

			TCHAR resName[255];

      // Относительный путь
			ksGetRelativePathFromSystemPathT( fileName,      // Полный путь к файлу
                                       resName,       // Результат - относительный путь к файлу( без системного пути )
                                       255,           // Размер буффера
                                       typeCatalog ); // Путь установленного типа см. ksSystemPath
			strMess = _T("Относительный путь к файлу ");
      strMess += userFile;
			strMess += _T("\n");
			strMess += catalogName[comm-1];
			strMess += _T("\n");
			strMess += resName;
			MessageW( strMess.c_bstr() );
    }
  }
}  