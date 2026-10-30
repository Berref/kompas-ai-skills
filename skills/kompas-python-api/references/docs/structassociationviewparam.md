# AssociationViewParam - Структура параметров ассоциативного вида

[Структуры параметров и константы](3d_define.html) > [Структуры параметров документов ](bk1829760.html) |  Scroll [ [ [ ](structassociationviewparamw.html "К следующему разделу")](bk1829760.html "На уровень выше")](bk1829760.html "К предыдущему разделу")  
---|---  
  
Аналог данных параметров при использовании Automation - интерфейс [ksAssociationViewParam](ksassociationviewparam.html).

ViewParam | viewPar | \- Параметры обычного вида, структура [ViewParam](structviewparam.html)  
---|---|---  
char | fileName [MAX_TEXT_LENGTH] | \- Имя файла документа-модели  
char | projectionName [TEXT_LENGTH] | \- Имя проекции (из списка проекций в документе-источнике)  
unsigned char | viewType | \- Тип вида из [LtViewType](ltviewtype.html) (параметр только для чтения)  
unsigned char | dimensionLayoutScaling | \- Признак масштабирования аннотационных объектов вида (только для SetObjParam)  
unsigned char | projectionLink | \- Проекционная связь  
unsigned char | disassembly | \- Разнести  
long | visibleLinesStyle | \- Номер стиля отрисовки видимых ребер и очерков, если 0 - умолчательный стиль  
long | hiddenLinesStyle | \- Номер стиля отрисовки всех невидимых линий, если 0 - умолчательный стиль  
long | tangentEdgesStyle | \- Номер стиля отрисовки видимых линий перехода, если 0 - умолчательный стиль  
unsigned char | hiddenLinesShow | \- Признак отрисовки невидимых линий  
unsigned char | tangentEdgesShow | \- Признак отрисовки видимых линий перехода  
unsigned char | projBodies | \- Признак проецирования тел  
unsigned char | projSurfaces | \- Признак проецирования поверхностей  
unsigned char | projThreads | \- Признак проецирования резьбы  
unsigned char | reserve[30] | \- Резерв  
HatchParamEx | hatchPar | \- Параметры штриховки, структура [HatchParamEx](structhatchparamex.html) (используется только в виде разрез\сечение)  
unsigned char | sameHatch | \- Одинаковая штриховка всех деталей сборки  
unsigned char | section | \- Признак разрез/сечение  
  
Примечание:

1\. Параметры могут быть получены с помощью метода [GetObjParam](getobjparam.html) с параметром ASSOCIATION_VIEW_PARAM.

2\. При использовании Unicode следует использовать структуру параметров [AssociationViewParamW](structassociationviewparamw.html).

Подразделы:

(отсутствуют)
