# ksDrawKompasTextW - Отрисовать текст в формате КОМПАС в окне (Unicode )

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksdrawslideex.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawkompastext.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawKompasText](kompasobject_ksdrawkompastext.html).

Синтаксис:

int LIB_FUNC ksDrawKompasTextW( void *HWindow, LPWSTR text );

Входной параметр:

HWindow | \- дескриптор окна для отрисовки слайда,  
---|---  
text | \- текст.  
  
Примечание.

При использовании ANSI следует использовать функцию [ksDrawKompasText](ksdrawkompastext.html).

Подразделы:

(отсутствуют)
