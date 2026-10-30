# ksDrawKompasText - Отрисовать текст в формате КОМПАС в окне

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции вывода на экран ](screen_output_fncts_common.html) |  Scroll [ [ [ ](ksdrawkompastextw.html "К следующему разделу")](screen_output_fncts_common.html "На уровень выше")](ksdrawkompasgroup.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [KompasObject::ksDrawKompasText](kompasobject_ksdrawkompastext.html).

Синтаксис:

int LIB_FUNC ksDrawKompasText( void *HWindow, LPSTR text );

Входной параметр:

HWindow | \- дескриптор окна для отрисовки слайда,  
---|---  
text | \- текст.  
  
Примечание.

При использовании Unicode следует использовать функцию [ksDrawKompasTextW](ksdrawkompastextw.html).

Подразделы:

(отсутствуют)
