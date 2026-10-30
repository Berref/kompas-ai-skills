# GetValidator - Получить валидатор

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции ввода параметров ](enter_params_common.html) |  Scroll [ [ [ ](ksexecdialpredefinedtext.html "К следующему разделу")](enter_params_common.html "На уровень выше")](cursor.html "К предыдущему разделу")  
---|---  
  
[Пример...](getvalidator_example.html)

Синтаксис:

void* GetValidator( void *min, void *max, unsigned char type);

Входные параметры:

min, max | \- границы интервала,  
---|---  
type | \- [тип данных](datatype.html).  
  
Возвращаемое значение:

указатель на Tvalidator | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи или если курсор находится не на поле чертежа.  
  
Примечание:

Функция работает только в OWL.

Подразделы:

(отсутствуют)
