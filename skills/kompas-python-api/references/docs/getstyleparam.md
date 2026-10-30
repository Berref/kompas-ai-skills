# GetStyleParam - Получить параметры стиля из документа

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Стили ](doc_styles_fncts.html) |  Scroll [ [ [ ](ksdeletestylefromdocument.html "К следующему разделу")](doc_styles_fncts.html "На уровень выше")](addstyle.html "К предыдущему разделу")  
---|---  
  
[Пример...](getstyleparam_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksGetStyleParam](ksdocument2d_ksgetstyleparam.html).

Синтаксис:

int GetStyleParam (unsigned char type,

unsigned short styleNumber,

void *param,

unsigned int sizePar);

Входные параметры:

type | \- [тип стиля](sttypes.html),  
---|---  
styleNumber | \- номер стиля,  
sizePar | \- размер структуры параметров.  
  
Выходные параметры:

param | \- указатель на структуру параметров стиля.  
---|---  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. В случае неудачи структура param заполняется параметрами стиля по умолчанию.

2\. Функция получает параметры стиля из документа. Различаются стили кривых, штриховок, текстов, оформления. В настоящее время функция реализована для стилей кривых и текстов.

3\. Для обыкновенного стиля кривых type равен CURVE_STYLE, param - указатель на структуру [CurveStyleParam](structcurvestyleparam.html).

4\. Для стиля кривых, содержащего фрагменты, type равен CURVE_STYLE_EX, param - указатель на структуру [CurveStyleParam](structcurvestyleparam.html).

5\. Для стиля текста type равен TEXT_STYLE, param - указатель на структуру [TextStyleParam](structtextstyleparam.html).

Подразделы:

(отсутствуют)
