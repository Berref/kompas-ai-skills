# WriteSlide - Записать выделенные объекты чертежа в формате векторного слайда КОМПАС

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](writeslidew.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](strresultw.html "К предыдущему разделу")  
---|---  
  
[Пример...](writeslide_example.html)

Аналог данной функции при использовании Automation - метод [KompasObject::ksWriteSlide](kompasobject_kswriteslide.html).

Синтаксис:

int WriteSlide ( char *filename, unsigned int ID, double x, double y );

Входной параметр:

filename | \- имя файла для записи,  
---|---  
ID | \- идентификатор слайда в файле ресурсов,  
x,y | \- базовая точка.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [WriteSlideW](writeslidew.html).

Подразделы:

(отсутствуют)
