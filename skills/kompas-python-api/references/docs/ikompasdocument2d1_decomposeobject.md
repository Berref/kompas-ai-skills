# DecomposeObject - Разбить объект на составляющие части - отрезки, дуги, тексты

[API интерфейсов. Версия 7](applicate.html) > [Документ ](doc.html) > [Базовые интерфейсы ](ba1711015.html) > [Интерфейс IKompasDocument2D1 ](ikompasdocument2d1.html) > [IKompasDocument2D1 - методы ](ikompasdocument2d1_methods.html) |  Scroll [ [ [ ](ikompasdocument2d1_deletehyperlinks.html "К следующему разделу")](ikompasdocument2d1_methods.html "На уровень выше")](ikompasdocument2d1_creatematrix.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](ikompasdocument2d1.html)

Синтаксис Automation:

LPDISPATCH DecomposeObject( IKompasAPIObject * Object, ksDecomposeObjectLevelEnum Level, double Arrow, ksDrawingObjectParamTypeEnum DecomposeType );

Синтаксис COM:

HRESULT DecomposeObject( IKompasAPIObject * Object, ksDecomposeObjectLevelEnum Level, double Arrow, ksDrawingObjectParamTypeEnum DecomposeType, IDrawingGroup * * Result );

Возвращаемое значение:

| \- Группа временных объектов [IDrawingGroup](idrawinggroup.html).  
---|---  
  
Входные параметры:

Object | \- указатель на объект,  
---|---  
Level | \- уровень декомпозиции из перечисления [ksDecomposeObjectLevelEnum](ksdecomposeobjectlevelenum.html),  
Arrow | \- стрелка прогиба,  
DecomposeType | \- признак выбранной системы координат из перечисления [ksDrawingObjectParamType](ksdrawingobjecparamtypeenum.html).  
  
Примечание:

1.Метод используется при разработке различных конверторов, преобразующих информацию из системы КОМПАС во внешние форматы.

2.Графический документ разбивается по частям. Такими частями могут быть объекты вида, основная надпись, технические требования, спецификация на листе, знак неуказанной шероховатости.

3.Сложные кривые заменяются набором отрезков и дуг (при Level = ksDOLSegmentsTextsPoints - только набором отрезков).

4.Точность приближения к исходному объекту задается значением параметра arrow - максимальным расстоянием между исходным объектом и аппроксимирующим отрезком.

5.Если Level = ksDOLSegmentsArcsTexts, точки превращаются в графические объекты, служащие для отрисовки этих точек в КОМПАС-ГРАФИК (например, в два отрезка для точки типа "крест"). В остальных случаях точки (в том числе отрисованные в виде "крестов", "треугольников" и т.д.) превращаются в объект типа "точка".

6.Во всех случаях, кроме level = ksDOLSegmentsArcsPoints, сложные тексты (например, тексты, написанные буквами разного начертания - прямого и курсивного) разбиваются на тексты с одинаковыми признаками. При level = ksDOLSegmentsArcsPoints тексты не изменяются.

7. Исходный объект после разбиения не изменяется.

Версия Компас v23

Подразделы:

(отсутствуют)
