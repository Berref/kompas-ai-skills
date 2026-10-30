# Типы динамических массивов

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Константы системы ](bk1808863.html) |  Scroll [ [ [ ](sttypes.html "К следующему разделу")](bk1808863.html "На уровень выше")](datatype.html "К предыдущему разделу")  
---|---  
  
| Для automation | Для API экспортных функций  
---|---|---  
CHAR_STR_ARR В зависимости от [типа компиляции..](_t.html) | 1 | \- динамический массив указателей на интерфейсы [ksChar255](kschar255.html) | \- динамический массив указателей на строки символов  
POINT_ARR | 2 | [\- динамический массив указателей на интерфейсы ](ksmathpointparam.html)[ksMathPointParam](ksmathpointparam.html) | \- динамический массив указателей на математические точки (структура [MathPointParam](structmathpointparam.html) )  
CURVE_PATTERN_ARR | 2 | \- динамический массив указателей на интерфейсы [ksCurvePattern](kscurvepattern.html) | \- динамический массив указателей на участки штриховой линии (структура [CurvePattern](structcurvepattern.html))  
TEXT_LINE_ARR | 3 | \- динамический массив указателей на интерфейсы [ksTextLineParam](kstextlineparam.html) | \- динамический массив строк текста (структура [TextLineParam](structtextlineparam.html))  
TEXT_ITEM_ARR | 4 | \- динамический массив указателей на интерфейсы [ksTextItemParam](kstextitemparam.html) | \- динамический массив компонент строк текста (структура [TextItemParam](structtextitemparam.html))  
ATTR_COLUMN_ARR | 5 | \- динамический массив указателей на интерфейсы [ksColumnInfoParam](kscolumninfoparam.html) | \- динамический массив колонок атрибутов (структура [ColumnInfo](structcolumninfo.html))  
USER_ARR | 6 | \- динамический пользовательский массив | \- динамический пользовательский массив  
POLYLINE_ARR | 7 | \- динамический массив указателей на интерфейсы [ksDynamicArray](ksdynamicarray.html) типа POINT_ARR | \- динамический массив полилиний (указателей массивов POINT_ARR)  
RECT_ARR | 8 | \- динамический массив указателей на интерфейсы [ksRectParam](ksrectparam.html) | \- динамический массив габаритных прямоугольников (структура [RectParam](structrectparam.html))  
LIBRARY_STYLE_ARR | 9 | \- динамический массив указателей на интерфейсы [ksLibraryStyleParam](kslibrarystyleparam.html) | \- динамический массив структур параметров для стиля в библиотеке стилей([LibraryStyleParam](structlibrarystyleparam.html) )  
VARIABLE_ARR | 10 | \- динамический массив указателей на интерфейсы [ksVariable](ksvariable.html) | \- динамический массив структур параметров параметрических переменных ([VariableParam](structvariableparam.html)[ )](structvariableparam.html)  
CURVE_PATTERN_ARR_EX | 11 | \- динамический массив указателей на интерфейсы [ksCurvePattern](kscurvepatternex.html) | \- динамический массив указателей на участки штриховой линии (структура [CurvePatternEx](structcurvepatternex.html)[)](structcurvepatternex.html)  
LIBRARY_ATTR_TYPE_ARR | 12 | \- динамический массив указателей на интерфейсы [ksLibraryAttrTypeParam](kslibraryattrtypeparam.html) | \- динамический массив структур параметров для типа атрибута в библиотеке типов атрибутов ([LibraryAttrTypeParam](structlibraryattrtypeparam.html)[)](structlibraryattrtypeparam.html)  
NURBS_POINT_ARR | 13 | \- динамический массив указателей на интерфейсы [ksNurbsPointParam](ksnurbspointparam.html) | \- динамический массив структур точек кривой NURBS ([NurbsPointParam](structnurbspointparam.html))  
DOUBLE_ARR | 14 | \- динамический массив указателей на интерфейсы [ksDoubleValue](ksdoublevalue.html) | \- динамический массив значений типа double  
CONSTRAINT_ARR | 15 | \- динамический массив указателей на интерфейсы [ksConstraintParam](ksconstraintparam.html) | \- динамический массив структур параметрических ограничений ([ConstraintParam](structconstraintparam.html))  
CORNER_ARR | 16 | \- динамический массив указателей на интерфейсы [ksCornerParam](kscornerparam.html) | \- динамический массив структур параметров скругленных (или усеченных) углов прямоугольников и многоугольников ([CornerParam](structcornerparam.html)) [Пример работы со структурой CornerParam и массивом CORNER_ARR](structcornerparam_example.html)  
DOC_SPCOBJ_ARR | 17 | \- динамический массив указателей на интерфейсы [ksDocAttachedSpcParam](ksdocattachedspcparam.html) | \- динамический массив структур параметров документов, подключенных к объекту спецификации ([DocAttachedSpcParam](structdocattachedspcparam.html))  
SPCSUBSECTION_ARR | 18 | \- динамический массив указателей на интерфейсы [ksSpcSubSectionParam](ksspcsubsectionparam.html) | \- динамический массив структур параметров подраздела спецификации [(SpcSubSectionParam](structspcsubsectionparam.html))  
SPCTUNINGSEC_ARR | 19 | \- динамический массив указателей на интерфейсы [ksSpcTuningSectionParam](ksspctuningsectionparam.html) | \- динамический массив структур параметров настройки раздела спецификации ([SpcTuningSectionParam](structspctuningsectionparam.html))  
SPCSTYLECOLUMN_ARR | 20 | \- динамический массив указателей на интерфейсы [ksSpcStyleColumnParam](ksspcstylecolumnparam.html) | \- динамический массив структур параметров стиля колонки спецификации ([SpcStyleColumnParam](structspcstylecolumnparam.html))  
SPCSTYLESEC_ARR | 21 | \- динамический массив указателей на интерфейсы [ksSpcStyleSectionParam](ksspcstylesectionparam.html) | \- динамический массив структур параметров стиля разделa спецификации ([SpcStyleSectionParam](structspcstylesectionparam.html))  
QUALITYITEM_ARR | 22 | \- динамический массив указателей на интерфейсы [ksQualityItemParam](ksqualityitemparam.html) | \- динамический массив структур параметров интервала квалитета ([QualityItemParam](structqualityitemparam.html))  
LTVARIANT_ARR | 23 | \- динамический массив указателей на интерфейсы [ksLtVariant](ksltvariant.html) | \- динамический массив структур для хранения данных некоторого типа ([LtVariant](structltvariant.html))  
TOLERANCEBRANCH_ARR | 24 | \- динамический массив указателей на интерфейсы [ksToleranceBranch](kstolerancebranch.html) | \- динамический массив структур параметров "опоры" допуска формы ([ToleranceBranch](structtolerancebranch.html))  
HATCHLINE_ARR | 25 | \- динамический массив указателей на интерфейсы [ksHatchLineParam](kshatchlineparam.html) | \- динамический массив структур ([HatchLineParam](structhatchlineparam.html))  
TREENODEPARAM_ARR | 26 | \- динамический массив указателей на интерфейсы [ksTreeNodeParam](kstreenodeparam.html) | \- динамический массив структур узла дерева [TreeNodeParam](structtreenodeparam.html)  
CHAR_STR_ARR_W [В зависимости от типа компиляции...](_t.html) | 27 |  | \- динамический массив указателей на строки символов. Используется в Unicode-вских структурах и функциях.  
  
Подразделы:

(отсутствуют)
