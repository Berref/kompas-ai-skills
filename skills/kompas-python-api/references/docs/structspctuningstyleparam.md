# SpcTuningStyleParam - Структура параметров настройки спецификации

[Структуры параметров и константы](3d_define.html) > [Структуры параметров спецификации ](bk1738516.html) |  Scroll [ [ [ ](structspctuningstyleparamw.html "К следующему разделу")](bk1738516.html "На уровень выше")](structspctuningsectionparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksSpcTuningStyleParam](ksspctuningstyleparam.html).

unsigned char | grToSP | связь сборочного чертежа со спецификацией (0 – нет связи, 1 - только вставка объектов спецификации, 2 - связь с расчетом позиций),  
---|---|---  
unsigned char | zoneCalc | расчет зон (1 - рассчитывать зоны, 0 - не рассчитывать зоны),  
unsigned char | showSectionName | показ имен разделов (1 - показывать имена разделов в таблице, 0 - не показывать имена разделов),  
unsigned char | positionCalc | расчет номеров позиций (1 - позиции рассчитывать 0 - позиции не рассчитывать),  
unsigned char | geometryDel | признак удаления геометрии удаленного объекта спецификации (1 - удалять геометрию при удалении объекта спецификации, 0 - не удалять геометрию),  
unsigned char | positionDel | зарезервировано,  
unsigned char | massCalc | зарезервировано,  
unsigned char | disableEmptyStr | наличие пустых строк вокруг заголовка раздела (1 - пустых строк нет, 0 - пустые строки есть),  
unsigned char | insertNull | префикс автоматически формируемого номера исполнения (1 - вставлять нули перед числом, 0 - не вставлять нули перед числом),  
unsigned char | insertDash | префикс автоматически формируемого номера исполнения (1 - вставлять тире перед числом, 0 - не вставлять тире перед числом),  
unsigned char | disableEmptyBlockStr | наличие пустых строк вокруг заголовка блока (1 - пустых строк нет, 0 - пустые строки есть),  
unsigned char | showInfoByDetBlock | порядок представления информации (0 - выдавать информацию блоками 1- выдавать информацию по объектам),  
unsigned char | ispolnOn | создание исполнений объектов в спецификации (1 - разрешено, 0 - запрещено),  
unsigned char | ispolnMarkFull | отображение номеров исполнений объектов (1 - обозначение исполнения показывать полностью, 0 - показывать только номер исполнения),  
unsigned char | blocOnNewPage | признак размещения блоков (1 - начинать блоки с новой страницы, 0 - начинать блоки после предыдущих),  
unsigned char | userTextStyle | стиль текста объектов спецификации (1 - пользовательский, 0 - из стиля спецификации),  
unsigned char | countIspoln | количество исполнений,  
unsigned char | countBlock | количество блоков,  
unsigned short | countIspolnEx | количество исполнений,  
unsigned short | countBlockEx | количество блоков,  
unsigned char | delSpcObjOnDelGeometry | удалять объекты спецификации при удалении геометрии,  
char | rezerv[5] | служебный параметр,  
[TextStyleParam](structtextstyleparam.html) | sectionTextStyleFirst | параметры стиля текста первой строки заголовков разделов,  
[TextStyleParam](structtextstyleparam.html) | sectionTextStyleNext | параметры стиля текста последующих строк заголовков разделов,  
[TextStyleParam](structtextstyleparam.html) | objectTextStyle | параметры стиля текста объектов спецификации,  
char | predefinedTextFileName [MAX_TEXT_LENGTH] | имя файла предопределенных текстов, использующегося при заполнении спецификации,  
reference | arrSection | массив структур параметров настроек разделов спецификации [SpcTuningSectionParam,](structspctuningsectionparam.html)  
| copySpcObjOnCopyGeometry | копировать объекты спецификации при копировании геометрии  
  
Примечания:

1\. Значение параметра showInfoByDetBlock учитывается, только если количество исполнений больше, чем количество колонок, предназначенных для записи количества на исполнение.

2\. В настоящее время параметр rezerv не используется.

3\. Параметры countIspoln и countBlock для совместимости заполняются для исполнений <= 255 и countIspolnEx == 0.

4\. При использовании Unicode следует использовать структуру параметров [SpcTuningStyleParamW](structspctuningstyleparamw.html).

Подразделы:

(отсутствуют)
