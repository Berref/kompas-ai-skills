# ksEditTextLine - Вызвать диалог редактирования сложноструктурированного текста

[API экспортных функций](export_function.html) > [Функции работы с графическим документом ](cm1726661.html) > [Простановка текстовых надписей ](cm1738402.html) > [Функции работы с текстовыми надписями и таблицами ](text_labels_fncts_common.html) |  Scroll [ [ [ ](ksedittextlinew.html "К следующему разделу")](text_labels_fncts_common.html "На уровень выше")](ksconverttexttocurve.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksEditTextLine](kompasobject_ksedittextline.html).

Синтаксис:

int ksEditTextLine (void *HWindow,

char *str,

int sizeStr);

Входные параметры:

HWindow | \- HWND окна,  
---|---  
sizeStr | \- размер строки str.  
  
Выходной параметр:

str | \- строка текста.  
---|---  
  
Возвращаемое значение:

1 | \- выход из диалога по кнопке OK,  
---|---  
0 | \- выход из диалога по кнопке Отмена.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksEditTextLineW](ksedittextlinew.html).

Подразделы:

(отсутствуют)
