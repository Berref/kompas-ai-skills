# Типы настроек для документов. Соответствие входных и выходных параметров

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
Типы настроек | Интерфейсы и структуры параметров  
---|---  
|  | Интерфейсы | Структуры параметров  
DIMENTION_OPTIONS | \- настройки размера, | [ksDimensionsOptions](ksdimensionsoptions.html) | [DimensionsOptions](structdimensionsoptions.html)  
ARROWFILLING_OPTIONS | \- признак зачернения стрелок, | [ksLtVariant](ksltvariant_intval.html) Может принимать значение, 0 - не зачернять или 1 - зачернять | int Может принимать значение, 0 - не зачернять или 1 - зачернять  
SHEET_OPTIONS | \- параметры листа; осталась для совместимости со старыми библиотеками. | [ksSheetOptions](kssheetoptions.html) | SheetPar  
SHEET_OPTIONS_EX | \- параметры листа активного документа, от текущего листа. | [ksSheetOptions](kssheetoptions.html) | [SheetOptions](sheetoptions.html)  
LENGTHUNITS_OPTIONS | \- настройки единиц измерений | [ksLtVariant](ksltvariant_shortval.html) Может принимать значение [размерности длины](lentypes.html), ST_MIX_SM, ST_MIX_M. | short Может принимать значение [размерности длины](lentypes.html), ST_MIX_SM, ST_MIX_M.  
SNAP_OPTIONS_EX | \- настройки привязок для активного документа | [ksSnapOptions](kssnapoptions.html) | [SnapOptions](snapoptions.html)  
OVERLAP_OBJECT_OPTIONS | \- настройки перекрывающихся объектов | [ksOverlapObjectOptions](ksoverlapobjectoptions.html) | [OverlapObjectOptions](overlapobjectoptions.html)
