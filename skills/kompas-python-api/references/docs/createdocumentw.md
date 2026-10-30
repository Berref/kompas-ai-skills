# CreateDocumentW - Создать документ (чертеж, фрагмент, текстовый документ, деталь, сборку) (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Общие функции ](common_docum_fncts.html) |  Scroll [ [ [ ](opendocument.html "К следующему разделу")](common_docum_fncts.html "На уровень выше")](createdocument.html "К предыдущему разделу")  
---|---  
  
[Пример...](create_open_close_save_documentw.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksCreateDocument](ksdocument2d_kscreatedocument.html).

Синтаксис:

reference LIB_FUNC CreateDocumentW (DocumentParamW * par);

Выходной параметр:

par | \- указатель на структуру параметров документа [DocumentParamW](structdocumentparamw.html).  
---|---  
  
Возвращаемое значение:

указатель на документ | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Документ может быть открыт как в видимом режиме, так и в невидимом (в этом случае документ не виден на экране и все операции над ним скрыты от пользователя).

2\. Созданный документ автоматически становится текущим.

3\. Документ не будет создан в случае, если уже открыт документ с таким же именем.

[4\. При использовании ANSI следует использовать функцию ](createdocument.html)[CreateDocument](createdocument.html).

Подразделы:

(отсутствуют)
