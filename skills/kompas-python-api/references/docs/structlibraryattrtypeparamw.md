# LibraryAttrTypeParamW - Структура параметров для типа атрибута в библиотеке типов атрибутов (Unicode)

[Структуры параметров и константы](3d_define.html) > [Структуры параметров атрибутов ](bk1733500.html) |  Scroll [ [ [ ](bk1838215.html "К следующему разделу")](bk1733500.html "На уровень выше")](structlibraryattrtypeparam.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html).

wchar_t | name [MAX_TEXT_LENGTH] | имя типа атрибута,  
---|---|---  
double | typeId | номер типа атрибута в библиотеке/  
  
Примечание:

1\. Параметры структуры могут быть получены с помощью метода [ksGetLibraryAttrTypesArray](ksgetlibraryattrtypesarray.html).

2\. Уникальный номер типа атрибута typeid может быть получен с помощью функции [GetAttrKeysInfo](getattrkeysinfo.html). Тип атрибута должен быть предварительно создан, например, с помощью функции [ksCreateAttrType](kscreateattrtype.html).

3\. При использовании ANSI следует использовать структуру параметров [LibraryAttrTypeParam](structlibraryattrtypeparam.html).

Подразделы:

(отсутствуют)
