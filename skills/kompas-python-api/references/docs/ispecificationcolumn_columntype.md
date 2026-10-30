# ColumnType - Тип колонки

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumn ](ispecificationcolumn.html) > [ISpecificationColumn - свойства ](ispecificationcolumn_props.html) |  Scroll [ [ [ ](ispecificationcolumn_columntypenumber.html "К следующему разделу")](ispecificationcolumn_props.html "На уровень выше")](ispecificationcolumn_columnname.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumn.html)

Тип данных: из перечисления [ksSpecificationColumnTypeEnum](ksspecificationcolumntypeenum.html)

Синтаксис Automation:

ColumnType = iObject.ColumnType | Получить свойство ([* ](1.html))  
---|---  
ColumnType = iObject.GetColumnType() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_ColumnType( &ColumnType ) | Получить свойство  
---|---  
  
Примечание:

1\. Тип колонки определяет, какая именно информация будет храниться в этой колонке (независимо от ее названия). Тип колонки используется при автоматическом выполнении различных операций. Например:

•если тип колонки - ПОЗИЦИЯ (ksSColumnPosition), то именно в эту колонку будут заноситься номера позиций при их автоматическом перерасчете;

•если тип колонки - ЗОНА (ksSColumnZone), то именно в эту колонку будут попадать номера зон;

•если тип колонки - ФОРМАТ (ksSColumnFormat), то в нее будут переноситься обозначения форматов из штампов чертежей деталей.

При перерождении спецификации в спецификацию другого стиля (например, простой спецификации в групповую) колонки превращаются в колонки такого же типа (если он есть в стиле той спецификации, в которую перерождается исходная).

2\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
