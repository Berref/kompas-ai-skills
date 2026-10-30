# WriteFragment - Записать группу во фрагмент

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Функции работы с фрагментами и библиотеками фрагментов ](cm1731223.html) > [Функции работы с фрагментами ](frags_fncts_common.html) > [Фрагменты ](frags_fncts.html) |  Scroll [ [ [ ](writefragmentw.html "К следующему разделу")](frags_fncts.html "На уровень выше")](localfragmentdefinitionw.html "К предыдущему разделу")  
---|---  
  
[Пример...](writefragment_example.html)

Аналог данной функции при использовании Automation - метод [ksFragment::ksWriteFragment](ksfragment_kswritefragment.html).

Синтаксис:

int WriteFragment (reference gr,

char *filename,

char *comment,

double xb,

double yb);

Входные параметры:

gr | \- указатель на группу (0 - записывается группа выделения),  
---|---  
filename | \- имя файла фрагмента,  
comment | \- комментарий для фрагмента,  
xb, yb | \- координаты точки привязки.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание.

При использовании Unicode следует использовать функцию [WriteFragmentW](writefragmentw.html).

Подразделы:

(отсутствуют)
