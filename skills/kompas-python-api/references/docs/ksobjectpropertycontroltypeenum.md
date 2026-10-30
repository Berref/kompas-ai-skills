# ksObjectPropertyControlTypeEnum - Типы контролов для отображения свойств в окне свойств

[Структуры параметров и константы](3d_define.html) > [Константы ](bk1803360.html) > [Константы системы ](bk1808863.html) |  Scroll [ [ [ ](kshotpointenum.html "К следующему разделу")](bk1808863.html "На уровень выше")](objtypes.html "К предыдущему разделу")  
---|---  
  
Константа |  | Тип контрола | Используемые поля в структуре [PropertyParam](propertyparam.html) кроме propertyType, propertyId, propertyInstance, isDefCpyProp, enable, и emptyValue  
---|---|---|---  
ksOPControlGroup | 0 | Группа свойств | -  
ksOPControlPointCoord | 1 | Координаты точки | propertyValue - Координата X VT_R8 additionData - Координата Y VT_R8  
ksOPControlPointStyle | 2 | Стиль точки 2D | propertyValue - Стиль точки из перечисления [ksAnnotationSymbolEnum](ksannotationsymbolenum.html) VT_I4  
ksOPControlLineStyle | 4 | Стиль линии 2D | propertyValue - Стиль линии из перечисления [ksCurveStyleEnum](kscurvestyleenum.html) или пользовательский VT_I4  
ksOPControlHatchStyle | 5 | Стиль штриховки | propertyValue - Стиль штриховки из перечисления [ksHatchStyleEnum](kshatchstyleenum.html) или пользовательский VT_I4  
ksOPControlColor | 6 | Цвет | propertyValue - Цвет VT_I4  
ksOPControlEditDouble | 7 | Вещественное значение | propertyValue - Значение VT_R8 propertyMinValue - Минимальное значение propertyMaxValue - Максимальное значение  
ksOPControlEditInt | 10 | Целое значение | propertyValue - Значение VT_I4 propertyMinValue - Минимальное значение propertyMaxValue - Максимальное значение  
ksOPControlListDouble | 11 | Список вещественных значений | propertyValue - Значение VT_R8 propertyMinValue - Минимальное значение propertyMaxValue - Максимальное значение additionData - Список значений VT_ARRAY | VT_R8 или VT_EMPTY для фиксированного списка загружаемого из ресурсов  
ksOPControlListInt | 12 | Список целых значений | propertyValue - Значение VT_I4 propertyMinValue - Минимальное значение propertyMaxValue - Максимальное значение additionData - Список значений VT_ARRAY | VT_I4 или VT_EMPTY для фиксированного списка загружаемого из ресурсов  
ksOPControlListCheck | 15 | Элемент который принимает два значения true, false | propertyValue - Значение VT_BOOL  
ksOPControlListBmp | 16 | Список с битмапами | propertyValue - Значение VT_I4 Идентификатор текущего битмапа  
ksOPControlListString | 17 | Список строк | propertyValue - Значение VT_BSTR additionData - Список значений VT_ARRAY | VT_BSTR или VT_EMPTY для фиксированного списка загружаемого из ресурсов  
ksOPControlSimpleText | 19 | Однострочный текст объекта |   
ksOPControlText | 25 | Многострочный текст |   
ksOPControlEdit | 31 | Строка | propertyValue - Значение VT_BSTR  
ksOPControlExternalEdit | 34 | Внешнее свойство с внешним редактированием. Отображает битмап | propertyValue - Значение любой простой тип Variant-а (Не отображается. Используется для сравнения значений) additionData - Значение любой тип (Не отображается. Не используется) propertyValue и additionData библиотека  
ksOPControlExternalStringEdit | 35 | Внешнее свойство с внешним редактированием. Отображает строку | propertyValue - Значение VT_BSTR  
ksOPControlFontImageList | 38 | Список со шрифтовыми иконками |   
ksOPControlExternalText | 44 | Однострочный текст объекта с внешним редактированием |   
ksOPControlExternalMultyText | 45 | Многострочный текст с внешним редактированием |   
ksOPControlUserLineStyle | 47 | Пользовательский стиль линии |   
  
Подразделы:

(отсутствуют)
