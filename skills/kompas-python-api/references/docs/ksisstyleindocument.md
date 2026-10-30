# ksIsStyleInDocument - Проверить, есть ли данный стиль в текущем документе

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Стили ](doc_styles_fncts.html) |  Scroll [ [ [ ](kssetobjectstyle.html "К следующему разделу")](doc_styles_fncts.html "На уровень выше")](ksgetobjectstyle.html "К предыдущему разделу")  
---|---  
  
[Пример...](ksisstyleindocument_ksdeletestylefromdocument_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksIsStyleInDocument](ksdocument2d_ksisstyleindocument.html).

Синтаксис:

int ksIsStyleInDocument (unsigned char type,

void * param,

unsigned int size,

unsigned char flag);

Входные параметры:

type | \- [тип стиля](sttypes.html),  
---|---  
flag | \- признак используемой структуры стиля: 0 - создать вручную, 1- взять стиль из библиотеки,  
size | \- размер структуры параметров.  
  
Выходные параметры:

param | \- указатель на структуру параметров стиля.  
---|---  
  
Возвращаемое значение:

1 | \- стиль в документе есть,  
---|---  
0 | \- стиля в документе нет.  
  
Примечание:

1\. В случае, если стиль задается вручную (flag = 0), требуется указать его параметры:

– для стиля кривой type = CURVE_STYLE, param - указатель на структуру [CurveStyleParam](structcurvestyleparam.html),

– для расширенного стиля кривой type = CURVE_STYLE_EX, param - указатель на структуру [CurveStyleParam](structcurvestyleparam.html),

– для стиля текста type = TEXT_STYLE, param - указатель на структуру [TextStyleParam](structtextstyleparam.html).

2\. В случае, когда стиль берется из библиотеки (flag = 1), требуется задать имя библиотеки и номер стиля: для стиля кривых и для стиля текста param - указатель на структуру LibStyle.

Подразделы:

(отсутствуют)
