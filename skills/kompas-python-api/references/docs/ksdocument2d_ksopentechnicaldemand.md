# ksOpenTechnicalDemand - Открыть технические требования

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_ksopenview.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_ksopendocument.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [OpenTechnicalDemand](opentechnicaldemand.html).

Синтаксис Automation:

long ksOpenTechnicalDemand (LPDISPATCH pGab,

long style);

Входные параметры:

pGab | \- указатель на интерфейс динамического массива [ksDynamicArray](ksdynamicarray.html) параметров листов технических требований типа RECT_ARR,  
---|---  
style | \- стиль текста для технических требований.  
  
[Системные стили текстов...](tstyles.html)

Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Примечание:

1\. Технические требования - составной объект оформления чертежа. Объекты [ksDocument2D::ksTextLine](ksdocument2d_kstextline.html), вводимые между ksOpenTechnicalDemand и [ksDocument2D::ksCloseTechnicalDemand](ksdocument2d_ksclosetechnicaldemand.html), принадлежат техническим требованиям.

2\. Технические требования могут состоять из нескольких строк, строки могут состоять из нескольких компонент. Компоненты могут изменять параметры текущего шрифта.

ksCloseTechnicalDemand возвращает указатель на технические требования.

Если style = 0, то стиль текста - умолчательный.

Подразделы:

(отсутствуют)
