/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc. 
  All rights reserved.
  Distributed under a BSD License. See LICENSE.txt file.

  This software is distributed "AS IS" WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the above copyright notice for more information.

=========================================================================*/
/*=========================================================================

   Program: ParaView
   Module:    $RCSfile$

   Copyright (c) 2005-2008 Sandia Corporation, Kitware Inc.
   All rights reserved.

   ParaView is a free software; you can redistribute it and/or modify it
   under the terms of the ParaView license version 1.2. 

   See License_v1.2.txt for the full ParaView license.
   A copy of this license can be obtained by contacting
   Kitware Inc.
   28 Corporate Drive
   Clifton Park, NY 12065
   USA

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/

#ifndef __ctkPythonShell_h
#define __ctkPythonShell_h

// Qt includes
#include <QWidget>

// CTK includes
#include "CTKScriptingPythonWidgetsExport.h"

/**
  Qt widget that provides an interactive "shell" interface to an embedded Python interpreter.
  You can put an instance of ctkPythonShell in a dialog or a window, and the user will be able
  to enter Python commands and see their output, while the UI is still responsive.
  
  \sa pqConsoleWidget, pqPythonDialog
*/  

class ctkAbstractPythonManager;

class CTK_SCRIPTING_PYTHON_WIDGETS_EXPORT ctkPythonShell :
  public QWidget
{
  Q_OBJECT
  
public:
  typedef QWidget Superclass; 
  ctkPythonShell(ctkAbstractPythonManager* pythonManager, QWidget* _parent = 0);
  ~ctkPythonShell();


  /// Initializes the interpretor. If an interpretor is already setup (by an
  /// earlier call to this method), it will be destroyed.
//   void initializeInterpretor(int argc, char* argv[]);
//   void initializeInterpretor();

  /// Prints some text on the shell.
  void printMessage(const QString&);

  /// Calls MakeCurrent in the internal vtkPVPythonInteractiveInterpretor instance
//   void makeCurrent();

  /// Calls ReleaseControl in the internal vtkPVPythonInteractiveInterpretor instance
//   void releaseControl();

  /// Given a python variable name, lookup its attributes and return them in a
  /// string list.
  QStringList getPythonAttributes(const QString& pythonVariableName);

signals:
  void executing(bool);

public slots:
  void clear();
  void executeScript(const QString&);

protected slots:
  void printStderr(const QString&);
  void printStdout(const QString&);

  void onExecuteCommand(const QString&);

private:
  ctkPythonShell(const ctkPythonShell&);
  ctkPythonShell& operator=(const ctkPythonShell&);

  void promptForInput();
  void internalExecuteCommand(const QString&);

  struct pqImplementation;
  pqImplementation* const Implementation;
};

#endif // !__ctkPythonShell_h