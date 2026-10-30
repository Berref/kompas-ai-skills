# ksGetReferenceDocumentPartEx - Получить указатель на объект оформления чертежа

[API интерфейсов. Версия 5](ag57940.html) > [Графический документ (Интерфейсы - ksDocument2D и IDocument2D) ](ksdocument2d.html) > [ksDocument2D - методы ](ksdocument2d_methods.html) > [Оформление чертежа ](bt1730281.html) |  Scroll [ [ [ ](ksdocument2d_ksgetviewnumber.html "К следующему разделу")](bt1730281.html "На уровень выше")](ksdocument2d_ksgetreferencedocumentpart.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ksdocument2d.html)

Аналог данного метода при использовании API экспортных функций - [GetReferenceDocumentPartEx](getreferencedocumentpartex.html).

Синтаксис Automation:

long ksGetReferenceDocumentPartEx (short t, long sheetNumb);

Входные параметры:

t | \- тип объекта оформления чертежа,  
---|---  
sheetNumb | \- зависит от типа получаемого объекта оформления чертежа: для t=0 sheetNumb - номер листа, начиная с 1, для t=1 sheetNumb не используется, для t=2 sheetNumb не используется, для t=3 sheetNumb не используется, для t=4 sheetNumb - номер спецификации, начиная с 1 (0 - текущая спецификация), для t=5 sheetNumb не используется, для t=6 sheetNumb - номер листа, начиная с 1.  
  
[Типы объектов оформления чертежа...](sheetobjtypes.html)

Возвращаемое значение:

указатель на объект выбранного типа | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
