////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки построения обозначений СПДС
//
////////////////////////////////////////////////////////////////////////////////
unit Step1_API7_2D_1;

interface
uses
  Sysutils, LDefin2D, ksAuto, Libtool, Windows;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); Pascal;
  function   LIBRARYID   : Cardinal;         Pascal;
  function   LoadStr( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;
  procedure  NewMarkOnLeader();
  procedure  NewMarkOnLine();
  procedure  NewMultiTextLeader();
  procedure  NewBrace;
  procedure  AddStrAxis;
  procedure  NewUnitnumber;
  procedure  NewDraft;
  procedure  NewUnitMarking;
  procedure  NewCutUnitMarking;

implementation

uses
  LtDefine,
  ksApi7,
  ksConstTLB,
  forms;


var
  newKompasAPI : IApplication;                                // Компас Application 7



//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; pascal;
begin
  Result := 100;  // IDR_LIB
end;
//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); pascal;
begin
  Application.Handle := GetHWindow;
  GetNewKompasAPI;
  if ( newKompasAPI <> nil ) then
  begin
    case command of
      1 : NewMarkOnLeader();  // Создать марку с линией-выноской                                     // Комманда 1
      2 : NewMarkOnLine();    // Создать марку.позиционное обозначение
      3 : NewMultiTextLeader(); //Создать ВЛКМО
      4 : NewBrace;             //Фигурная скобка
      5 : AddStrAxis;           //Прямая координационная ось
      6 : NewUnitnumber;        //Номер узла на чертеже
      7 : NewDraft;        //Новый чертеж
      8 : NewUnitMarking;    //Обозначение узла
      9 : NewCutUnitMarking;    //Обозначение узла в сечении
  end;
  newKompasAPI := nil;
end;
end;

//-------------------------------------------------------------------------------
// Получить указатель на интерфейс коллекции видов (COM)
// ---
function GetViews : IViews;

var
   pKompasDocument2D : IKompasDocument2D;
   pViewsAndLayersManager : IViewsAndLayersManager;
begin
  Result := nil;
  //Получить указатель на интерфейс документа Компас
  pKompasDocument2D := newKompasAPI.ActiveDocument As IKompasDocument2D;
  if ( pKompasDocument2D <> nil) then
  begin
    //Получить указатель на интерфейс менеджера видов и слоёв
    pViewsAndLayersManager := pKompasDocument2D.ViewsAndLayersManager;

    if ( pViewsAndLayersManager <> nil ) then
    begin
      Result := pViewsAndLayersManager.Views;
    end;
  end;
end;

//-------------------------------------------------------------------------------
// _1_ Создать марку с линией-выноской
// ---
procedure NewMarkOnLeader;

var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  ppMarks : IMarks;
  pMarkOnL : IMarkOnLeader;
  pTextAfter : IText;
  strAfter : WideString;

begin
  //Получить указатель на коллекцию видов
  ppViews := GetViews();
    if( ppViews <> nil ) then
    begin
      //Получить указатель на интерфейс вида
      //Свойство ActiveView- возвращает указатель на активный вид
      ppView := ppViews.ActiveView;
      //нет проверки потому что As ее выполняет
      //Получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;

        if (  ppBuildingContainer <> nil ) then
        begin
          //Получить указатель на коллекцию марок
          ppMarks := ppBuildingContainer.Marks;
          if( ppMarks <> nil ) then
          begin
            //Получить указатель на марку
            pMarkOnL := ppMarks.Add( ksDrMarkOnLeader	) As IMarkOnLeader;
            if ( pMarkOnL <> nil )then
              begin
                //Задать параметры марки
                pMarkOnL.X := 250;
                pMarkOnL.Y := 150;
                pMarkOnL.ArrowType := ksLeaderArrow;
                pMarkOnL.ShelfDirection := ksLSUp;
                pMarkOnL.AddBranchByPoint( 1, FALSE, 100, 100);
                //Показать марку
                pMarkOnL.Update();
                //Задать параметры текста
                pTextAfter := pMarkOnL.TextAfter;
                strAfter := 'текст марки';
                pTextAfter.Str :=  strAfter;
                //Обновить марку
                pMarkOnL.Update();

              end
          end
        end
    end;
    ksMessage('Марка с линией-выноской - пробва');
end;
//-------------------------------------------------------------------------------
// _2_ Создать марку/позиционное обозначение
// ---
procedure NewMarkOnLine;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pDrawingContainer : IDrawingContainer;
  ppMarks : IMarks;
  pMarkOnLine : IMarkOnLine;
  pTextAfter : IText;
  strAfter : WideString;
  pLineSegments : ILineSegments;
  pLineSegment : ILineSegment;
begin
  ppViews := GetViews();
  if( ppViews <> nil ) then
  begin
    //Получить указатель на интерфейс вида
    //Свойство ActiveView- возвращает указатель на активный вид
    ppView := ppViews.ActiveView;
      //построение отрезка - объект для размещения марки
      //Получить указатель на контейнер графических объектов
          pDrawingContainer := ppView As IDrawingContainer;
           if (  pDrawingContainer <> nil ) then
           begin
            //Получить указатель на коллекцию отрезков
            pLineSegments := pDrawingContainer.LineSegments;
             if( pLineSegments <> nil)  then
             begin
                //Получить указатель на отрезок
                pLineSegment := pLineSegments.Add;
                  if ( pLineSegment <> nil )then
                  begin

                    pLineSegment.X1   := 100 ;
                    pLineSegment.Y1   := 100 ;
                    pLineSegment.X2   := 150 ;
                    pLineSegment.Y2   := 110 ;
                    // Установить стиль линии
                    pLineSegment.Style  := 1 ;
                    //Показать отрезок
                    pLineSegment.Update();
                  end
             end
           end;
        //Получить указатель на контейнер объектов СПДС
        ppBuildingContainer := ppView As IBuildingContainer;
          if (  ppBuildingContainer <> nil ) then
          begin
            //Получить указатель на коллекцию марок
            ppMarks := ppBuildingContainer.Marks;
              if( ppMarks <> nil)  then
              begin
                //Получить указатель на марку
                pMarkOnLine := ppMarks.Add( ksDrMarkOnLine	) As IMarkOnLine;
                  if ( pMarkOnLine <> nil )then
                  begin
                    //Задать строку текста
                    pTextAfter := pMarkOnLine.TextAfter;
                    strAfter := 'текст после';
                    pTextAfter.Str :=  strAfter;
                    //Указать объект для построения марки
                    pMarkOnLine.Line := pLineSegment;
                    //Указать положение  марки
                    pMarkOnLine.Position := ksMTextOnLine;
                    //Показать марку
                    pMarkOnLine.Update();
                  end
              end
          end;
    ksMessage('Марка/позиционное обозначение');
  end;
end;

//-------------------------------------------------------------------------------
// 3 Создать выносную надпись к многослойным конструкциям (ВНМК)
// ---
procedure NewMultiTextLeader;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pMTLs : IMultiTextLeaders;
  pMTL : IMultiTextLeader;
  pText : IText;
  strAfter : WideString;
begin
  ppViews := GetViews();
  if( ppViews <> nil ) then
  begin
    //Получить указатель на интерфейс вида
    //Свойство ActiveView- возвращает указатель на активный вид
    ppView := ppViews.ActiveView;
    if( ppView <> nil ) then
    begin
      //получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;
      if( ppBuildingContainer <> nil ) then
      begin
        //Получить указатель на коллекцию выносных линий к многослойным объектам (ВЛКМО)
        pMTLs := ppBuildingContainer.MultiTextLeaders;
        if(pMTLs <> nil) then
        begin
          //Получить указатель на ВЛКМО
          pMTL := pMTLs.Add;
          if( pMTL <> nil) then
          begin
            //Задать параметры ВЛКМО
            pMTL.Form := TRUE;
            pMTL.ArrowType := ksLeaderArrow;
            pMTL.ShelfX := 250;
            pMTL.ShelfY := 250;
            pMTL.TextDirection := TRUE;
            pMTL.ShelfDirection := ksLSRight;
            //Добавить ответвления
            pMTL.AddBranchByPoint( 1, 100, 100);
            pMTL.AddBranchByPoint( -1, 120, 100);
            pMTL.AddBranchByPoint( -1, 130, 100);
            //Задать строку текста
              pText := pMTL.Text;
              strAfter := 'текст ВЛКМО';
              pText.Str :=  strAfter;
             //Показать ВЛКМО
            pMTL.Update();
          end
        end
      end;
    end;
  end;
  ksMessage('Выносная надпись к многослойным конструкциям');
end;

//-------------------------------------------------------------------------------
// 4 Создать фигурную скобку
// ---
procedure NewBrace;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pBraces : IBraces;
  pBrace : IBrace;
  pText : IText;
  strText : WideString;
begin
  ppViews := GetViews();
  if( ppViews <> nil ) then
  begin
    //Получить указатель на интерфейс вида
    //Свойство ActiveView- возвращает указатель на активный вид
    ppView := ppViews.ActiveView;
    if( ppView <> nil ) then
    begin
      //получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;
      if( ppBuildingContainer <> nil ) then
      begin
        //Получить указатель на коллекцию скобок
        pBraces := ppBuildingContainer.Braces;
        if(pBraces <> nil) then
        begin
          //Получить указатель на скобку
          pBrace := pBraces.Add;
          if( pBrace <> nil) then
          begin
            //Задать параметры скобки
            pBrace.X1 := 100;
            pBrace.Y1 := 100;
            pBrace.Alignment := 0;
            pBrace.Angle := 145;
            pBrace.Direction := FALSE;
            pBrace.Length := 100;
            pBrace.Radius := 8;
            pBrace.ShelfDirection := ksLSRight;
            pBrace.Style := 7;

            //Задать строку текста
              pText := pBrace.Text;
              strText := 'текст скобки';
              pText.Str :=  strText;
             //Показать скобку
            pBrace.Update();
          end
        end
      end;
    end;
  end;
  ksMessage('Фигурная скобка');
end;


//-------------------------------------------------------------------------------
//  Создание прямой координационной оси.
//
// ---
procedure AddStrAxis();
var
  pViews : IViews;
  pView  : IView;
  pBuildContainer : IBuildingContainer;
  pAxes : IBuildingAxes;
  pAxis : IStraightAxis;
  pText : IText;
  pText1 : IText;
  pText2 : IText;
  pText3 : IText;
  pText4 : IText;
  pText1l : IText;
  pText2r : IText;
  pText01r : Itext;
  strText : WideString;
  strText1 : WideString;
  strText2 : WideString;
  strText3 : WideString;
  strText4 : WideString;
  strText1l : WideString;
  strText2r : WideString;
  strText01r : WideString;
  pNodes : IMarkNodes;
  pNodes1l : IMarkNodes;
  pNodes0l : IMarkNodes;
  pNodes0r : IMarkNodes;
  pNodes2R : IMarkNodes;
  pNode0 : IMarkNode;
  pNode1 : IMarkNode;
  pNode2 : IMarkNode;
  pNode3 : IMarkNode;
  pNode4 : IMarkNode;
  pNode0l1 : IMarkNode;
  pNode0lr : IMarkNode;
  pNode1l1 : IMarkNode;
  pNode2r1 : IMarkNode;
  pJut1 : IAxisJut;
  pJut2: IAxisJut;
begin
  // получить коллекцию видов
  pviews := GetViews();
  if ( pviews <> nil ) then
  begin
    //получить указатель на интерфейс вида
    pView := pViews.ActiveView;
    //Получить указатель на контейнер объектов СПДС
    pBuildContainer := pView As IBuildingContainer;
      if ( pBuildContainer <> nil )then
      begin
        // получить коллекцию строительных осей
        pAxes := pBuildContainer.BuildingAxes;
        if (pAxes <> nil ) then
        begin
        //Получить указатель на интерфейс оси
          pAxis := pAxes.Add ( ksDrStraightAxis	) As IStraightAxis;
          if ( pAxis <> nil ) then
          begin
            //Задать параметры оси
            pAxis.Angle := 60;
            pAxis.Length := 70;
            pAxis.DoubleMark := TRUE;
            pAxis.MarkSize := 30;
            pAxis.X1 := 100;
            pAxis.Y1 := 100;
              //Задать параметры выступа
              //Получить указатель на интерфейс выступа 1
              pJut1 := pAxis.Jut[TRUE];
                if ( pJut1 <> nil ) then
                begin
                pJut1.MarkOn := TRUE;
                pJut1.BreakDirection := TRUE;
                pJut1.BreakOffset := 25;
                pJut1.Length := 30;
                pJut1.MarkOffset := 24;

                end;
              //Получить указатель на интерфейс выступа 2
              pJut2 := pAxis.Jut[FALSE];
                if ( pJut2 <> nil ) then
                begin
                pJut2.MarkOn := TRUE;
                pJut2.BreakDirection := TRUE;
                pJut2.BreakOffset := 25;
                pJut2.Length := 30;
                pJut2.MarkOffset := 24;

                end;

            //Задать строку текста
              pText := pAxis.Text;
              strText := 'Прямая ось';
              pText.Str :=  strText;

            pAxis.Update();
             //Получить коллекцию узлов у оси
              pNodes := pAxis.MarkNodes;
              if (pNodes <> nil ) then
              begin
              //получить указатель на нулевой узел
                pNode0 := pNodes.Item [0];
                if (pNode0 <> nil ) then
                begin
                  //Получить указатель на коллекцию узлов слева от нулевого
                  pNodes0l := pNode0.MarkNodes[true];
                         if (pNodes0l <> nil ) then
                         begin
                         //получить указатель на первый узел
                         pNode0l1 := pNodes0l.Add ( ksMarkRefCircle, -1 );
                          if ( pNode0l1 <> nil ) then
                          begin
                          pNode0l1.DoubleMark := TRUE;
                          pNode0l1.RefLength := 40;
                          end
                         end;
                   pNodes0r := pNode0.MarkNodes[false];
                         if (pNodes0r <> nil ) then
                         begin
                         //получить указатель на первый узел
                         pNode0lr := pNodes0r.Add ( ksMarkText, -1 );
                          if ( pNode0lr <> nil ) then
                          begin
                          //Текст узла справа
                          pText01r := pNode0lr.Text;
                          strText01r := 'Первый узел справа от нулевого';
                          pText01r.Str :=  strText01r;
                          end
                         end
                end;

              //получить указатель на первый узел
                pNode1 := pNodes.Add ( ksMarkCircle, -1 );
                if ( pNode1 <> nil) then
                begin
                //Задать строку текста
                pText1 := pNode1.Text;
                strText1 := 'Самый Первый узел';
                pText1.Str :=  strText1;
                pAxis.Update();

                  pNode2 := pNodes.Add ( ksMarkCircle, -1 );
                  if ( pNode2 <> nil) then
                  begin
                  pText2 := pNode2.Text;
                  strText2 := 'Второй узел';
                  pText2.Str :=  strText2;

                    pNode3 := pNodes.Add ( ksMarkCircle, -1 );
                    if ( pNode3 <> nil ) then
                    begin
                    //Задать строку текста
                    pText3 := pNode3.Text;
                    strText3 := 'Третий узел';
                    pText3.Str :=  strText3;

                      pNode4 := pNodes.Add ( ksMarkRefCircle, -1 );
                      if ( pNode3 <> nil ) then
                      begin
                      //Задать строку текста
                      pText4 := pNode4.Text;
                      strText4 := 'Четвертый узел';
                      pText4.Str :=  strText4;

                        if ( pNode1 <> nil) then
                      //получить коллекцию узлов слева от первого дополнительного
                        begin
                         pNodes1l := pNode1.MarkNodes[true];
                         if (pNodes1l <> nil ) then
                         begin
                         //получить указатель на первый узел
                         pNode1l1 := pNodes1l.Add ( ksMarkRefCircle, -1 );
                          if ( pNode1l1 <> nil ) then
                          begin
                          pNode1l1.DoubleMark := TRUE;
                          pNode1l1.RefLength := 50;
                          //Текст первого узла слева
                          pText1l := pNode1l1.Text;
                          strText1l := 'Узел слева';
                          pText1l.Str := strText1l;
                            //Получить коллекцию узлов справа
                            if ( pNode2 <> nil) then
                            begin
                            pNodes2r := pNode2.MarkNodes[false];
                              if ( pNodes2r <> nil ) then
                              begin
                              //Получить указатель на узел справа
                              pNode2r1 := pNodes2r.Add ( ksMarkText, -1);
                              //Текст первого узла слева
                              pText2r := pNode2r1.Text;
                              strText2r := 'Узел справа';
                              pText2r.Str := strText2r;

                              end
                            end
                          end
                         end
                        end;
                      pAxis.Update();
                      end
                    end
                  end
                end
              end
          end
        end
      end
    end;
      ksMessage ( 'Прямая координационная ось' );
end;
//-------------------------------------------------------------------------------
// __ Создать номер узла на чертеже
// ---
procedure NewUnitnumber;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pUNumbers : IUnitNumbers;
  pUNumber : IUnitNumber;
  pTextUp : IText;
  pTextDown : IText;
  strTxtUp : WideString;
  strTxtDown : WideString;
begin
  //Получить указатель на коллекцию видов
  ppViews := GetViews();
    if( ppViews <> nil ) then
    begin
      //Получить указатель на интерфейс вида
      //Свойство ActiveView- возвращает указатель на активный вид
      ppView := ppViews.ActiveView;
      //нет проверки потому что As ее выполняет
      //Получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;

        if (  ppBuildingContainer <> nil ) then
        begin
          //Получить указатель на коллекцию номеров узлов
          pUNumbers := ppBuildingContainer.UnitNumbers;
          if( pUNumbers <> nil ) then
          begin
            //Получить указатель на номер узла
            pUNumber := pUNumbers.Add() As IUnitNumber;
            if ( pUNumber <> nil )then
              begin
                //Задать параметры номера узла
                pUNumber.X := 150;
                pUNumber.Y := 100;

                //Задать параметры текста сверху
                pTextUp := pUNumber.TextUp;
                strTxtUp := 'Текст номера сверху';
                pTextUp.Str :=  strTxtUp;

                //Задать параметры текста снизу
                pTextDown := pUNumber.TextDown;
                strTxtDown := 'Текст номера снизу';
                pTextDown.Str :=  strTxtdown;
                //Обновить марку
                pUNumber.Update();
              end
          end
        end
    end;
    ksMessage('Номер узла на чертеже');
end;


//-------------------------------------------------------------------------------
// __ Создать обозначение узла на чертеже
// ---
procedure NewUnitMarking;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pUMarkings : IUnitMarkings;
  pUMarking : IUnitMarking;
  pTextUp : IText;
  pTextDown : IText;
  strTxtUp : WideString;
  strTxtDown : WideString;
begin
  //Получить указатель на коллекцию видов
  ppViews := GetViews();
    if( ppViews <> nil ) then
    begin
      //Получить указатель на интерфейс вида
      //Свойство ActiveView- возвращает указатель на активный вид
      ppView := ppViews.ActiveView;
      //нет проверки потому что As ее выполняет
      //Получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;

        if (  ppBuildingContainer <> nil ) then
        begin
          //Получить указатель на коллекцию обозначений узлов
          pUMarkings := ppBuildingContainer.UnitMarkings;
          if( pUMarkings <> nil ) then
          begin
            //Получить указатель на обозначение узла
            pUMarking := pUMarkings.Add() As IUnitMarking;
            if ( pUMarking <> nil )then
              begin
                //Задать параметры обозначения узла
                pUMarking.Xc := 150;
                pUMarking.Yc := 300;
                pUMarking.Form := ksUFormCRectangle;
                pUMarking.Height := 25;
                pUMarking.Width := 30;
                pUMarking.ShelfX := 180;
                pUMarking.ShelfY := 340;
                pUMarking.ShelfDirection := ksLSRight;
                //Задать параметры текста сверху
                pTextUp := pUMarking.TextUp;
                strTxtUp := 'Текст обозначения узла сверху';
                pTextUp.Str :=  strTxtUp;

                //Задать параметры текста снизу
                pTextDown := pUMarking.TextDown;
                strTxtDown := 'Текст обозначения узла снизу';
                pTextDown.Str :=  strTxtdown;
                //Обновить марку
                pUMarking.Update();
              end
          end
        end
    end;
    ksMessage('Обозначение узла на чертеже');
end;


//-------------------------------------------------------------------------------
// __ Создать обозначение узла в сечении на чертеже
// ---
procedure NewCutUnitMarking;
var
  ppViews : IViews;
  ppView  : IView;
  ppBuildingContainer : IBuildingContainer;
  pCUMarkings : ICutUnitMarkings;
  pCUMarking : ICutUnitMarking;
  pTextUp : IText;
  pTextDown : IText;
  strTxtUp : WideString;
  strTxtDown : WideString;
begin
  //Получить указатель на коллекцию видов
  ppViews := GetViews();
    if( ppViews <> nil ) then
    begin
      //Получить указатель на интерфейс вида
      //Свойство ActiveView- возвращает указатель на активный вид
      ppView := ppViews.ActiveView;
       //Получить указатель на контейнер объектов СПДС
      ppBuildingContainer := ppView As IBuildingContainer;
        if (  ppBuildingContainer <> nil ) then
        begin
          //Получить указатель на коллекцию обозначений узлов
          pCUMarkings := ppBuildingContainer.CutUnitMarkings;
          if( pCUMarkings <> nil ) then
          begin
            //Получить указатель на обозначение узла
            pCUMarking := pCUMarkings.Add() As ICutUnitMarking;
            if ( pCUMarking <> nil )then
              begin
                //Задать параметры обозначения узла
                pCUMarking.Angle := 45;
                pCUMarking.ShelfDirection := ksLSRight;
                pCUMarking.ShelfX := 160;
                pCUMarking.ShelfY := 160;

                pCUMarking.AddStroke( 100, 65, 25);
                pCUMarking.AddStroke( 120, 95, 25);
                pCUMarking.AddStroke( 145, 135, 15);


                //Задать параметры текста сверху
                pTextUp := pCUMarking.TextUp;
                strTxtUp := 'Текст обозначения узла сверху';
                pTextUp.Str :=  strTxtUp;

                //Задать параметры текста снизу
                pTextDown := pCUMarking.TextDown;
                strTxtDown := 'Текст обозначения узла снизу';
                pTextDown.Str :=  strTxtdown;
                //Обновить марку
                pCUMarking.Update();
              end
          end
        end
    end;
    ksMessage('Обозначение узла в сечении на чертеже');
end;


//-------------------------------------------------------------------------------
//  Создать новый документ
// ---
procedure NewDraft;
var
  pDocs : IDocuments;
  pDoc  : IKompasDocument;
  lSheets : ILayoutSheets;

  num : Integer;
  buf : AnsiString;
begin
  if( newKompasAPI <> nil ) then
  begin
  pDocs := newKompasAPI.Documents;
    if ( pDocs <> nil) then
    begin
    pDoc := pDocs.Add( ksDocumentSpecification, TRUE );
    lSheets := pDoc.LayoutSheets;
      if (lSheets <> nil) then
      begin
      num := lSheets.count;
      buf := Format ('count=%d', [num]);
      ksMessage(PAnsiChar(buf));
      end
      else
      ksMessage ('Ошибка');
    end
  end
end;


//-------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
var
  disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch(CreateKompasApplication);
    newKompasAPI := disp As IApplication;
  end;
end;

//----------------------------------------------------------------------------------------------
// Зогрузить строку из ресурсов
//---
function LoadStr( ID : Integer ) : string;
var
  buf : array [0..255] of AnsiChar;
begin
  ksConvertLangStrEx( hInstance, ID, buf, 255 );
  Result := buf;
end;

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessage( str : string; flags : integer ) : Integer;
var
 enabse : Integer;
begin
  enabse := IsEnableTaskAccess();  // проверка доступа
  if enabse <> 0 then             // если доступ к задаче разрешен
    EnableTaskAccess(0);          // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
  Result := Application.MessageBox( PChar(str), PChar(LoadStr(LIBRARYID)), flags );

  if enabse <> 0 then                         // если доступ к задаче был запрещен
    EnableTaskAccess(1);              // разрешаем доступ к задаче


end;

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessageByID( strId, flags : Integer ) : Integer;
begin
  Result := LibMessage( LoadStr(strId), flags );
end;

end.


