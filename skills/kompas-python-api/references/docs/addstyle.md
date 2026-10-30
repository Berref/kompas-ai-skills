# AddStyle - Добавить стиль

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Функции настройки документа и работы со стилями ](doc_tunes_fncts.html) > [Стили ](doc_styles_fncts.html) |  Scroll [ [ [ ](getstyleparam.html "К следующему разделу")](doc_styles_fncts.html "На уровень выше")](doc_styles_fncts.html "К предыдущему разделу")  
---|---  
  
[Пример...](addstyle_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksAddStyle](ksdocument2d_ksaddstyle.html).

Синтаксис:

unsigned short AddStyle (unsigned char type,

void *param,

unsigned int sizePar,

unsigned char flag);

Входные параметры:

type | \- [тип стиля](sttypes.html),  
---|---  
param | \- указатель на структуру параметров стиля,  
flag | \- признак создания стиля: 0 - создать вручную, 1- взять стиль из библиотеки,  
sizePar | \- размер структуры параметров стиля.  
  
Возвращаемое значение:

идентификатор стиля | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечания:

1\. В настоящее время функция реализована для стилей кривых, текстов и штриховок.

2\. При копировании стиля из библиотеки param - указатель на интерфейс [ksLibStyle](kslibstyle.html).

3\. При создании стиля вручную:

– для обыкновенного стиля кривых type равен CURVE_STYLE, param - указатель на структуру [CurveStyleParam](structcurvestyleparam.html).

– для стиля кривых, содержащего фрагменты, type равен CURVE_STYLE_EX, param - указатель на структуру CurveStyleParam.

– для стиля текста type равен TEXT_STYLE, param - указатель на структуру [TextStyleParam](structtextstyleparam.html).

Подразделы:

(отсутствуют)
