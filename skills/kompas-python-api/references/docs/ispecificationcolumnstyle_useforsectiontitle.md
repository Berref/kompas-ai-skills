# UseForSectionTitle - Использовать колонку для вывода имени раздела

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) > [Интерфейс ISpecificationColumnStyle ](ispecificationcolumnstyle.html) > [ISpecificationColumnStyle - свойства ](ispecificationcolumnstyle_props.html) |  Scroll [ [ [ ](ispecificationcolumnstyle_usein3d.html "К следующему разделу")](ispecificationcolumnstyle_props.html "На уровень выше")](ispecificationcolumnstyle_textdown.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ispecificationcolumnstyle.html)

Тип данных: BOOL

Синтаксис Automation:

UseForSectionTitle = iObject.UseForSectionTitle | Получить свойство ([* ](1.html))  
---|---  
UseForSectionTitle = iObject.GetUseForSectionTitle() | Получить свойство ([**](2.html))  
  
Синтаксис COM:

iObject->get_UseForSectionTitle (&UseForSectionTitle) | Получить свойство  
---|---  
  
Значения свойства:

TRUE | \- в колонке будут располагаться заголовки разделов спецификации,  
---|---  
FALSE | \- колонка будет пустой для объектов спецификации "Имя раздела".  
  
Примечание:

1\. В стандартных спецификациях заголовки разделов обычно располагаются в колонке Наименование. Значение этого свойства TRUE - может быть только для одной колонки спецификации. Если у всех колонок значение этого свойства FALSE, заголовки разделов показываться не будут (даже при включении в настройке разделов опции Показывать заголовки разделов).

2\. Используется только для основных колонок спецификации.

3\. Используется только для колонок, полученных у стиля спецификации [ISpecificationStyle](ispecificationstyle.html).

4\. Свойство доступно только для чтения.

Подразделы:

(отсутствуют)
