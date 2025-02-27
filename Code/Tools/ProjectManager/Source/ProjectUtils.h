/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
#pragma once

#include <ScreenDefs.h>
#include <ProjectInfo.h>
#include <ProjectManagerDefs.h>

#include <QWidget>
#include <QProcessEnvironment>

#include <AzCore/IO/Path/Path_fwd.h>
#include <AzCore/Outcome/Outcome.h>

namespace O3DE::ProjectManager
{
    namespace ProjectUtils
    {
        bool AddProjectDialog(QWidget* parent = nullptr);
        bool RegisterProject(const QString& path);
        bool UnregisterProject(const QString& path);
        bool CopyProjectDialog(const QString& origPath, ProjectInfo& newProjectInfo, QWidget* parent = nullptr);
        bool CopyProject(const QString& origPath, const QString& newPath, QWidget* parent, bool skipRegister = false);
        bool DeleteProjectFiles(const QString& path, bool force = false);
        bool MoveProject(QString origPath, QString newPath, QWidget* parent, bool skipRegister = false);

        bool ReplaceProjectFile(const QString& origFile, const QString& newFile, QWidget* parent = nullptr, bool interactive = true);

        bool FindSupportedCompiler(QWidget* parent = nullptr);
        AZ::Outcome<QString, QString> FindSupportedCompilerForPlatform();

        ProjectManagerScreen GetProjectManagerScreen(const QString& screen);

        /**
         * Execute a console command and return the result.
         * @param cmd the command
         * @param arguments the command argument list
         * @param processEnv the environment 
         * @param commandTimeoutSeconds the amount of time in seconds to let the command run before terminating it 
         * @return AZ::Outcome with the command result on success
         */
        AZ::Outcome<QString, QString> ExecuteCommandResult(
            const QString& cmd,
            const QStringList& arguments,
            int commandTimeoutSeconds = ProjectCommandLineTimeoutSeconds);

        /**
         * Execute a console command, display the progress in a modal dialog and return the result.
         * @param cmd the command
         * @param arguments the command argument list
         * @param processEnv the environment 
         * @param commandTimeoutSeconds the amount of time in seconds to let the command run before terminating it 
         * @return AZ::Outcome with the command result on success
         */
        AZ::Outcome<QString, QString> ExecuteCommandResultModalDialog(
            const QString& cmd,
            const QStringList& arguments,
            const QString& title);

        AZ::Outcome<void, QString> SetupCommandLineProcessEnvironment();
        AZ::Outcome<QString, QString> GetProjectBuildPath(const QString& projectPath);
        AZ::Outcome<void, QString> OpenCMakeGUI(const QString& projectPath);
        AZ::Outcome<QString, QString> RunGetPythonScript(const QString& enginePath);

        /**
         * Create a desktop shortcut.
         * @param filename the name of the desktop shorcut file 
         * @param target the path to the target to run 
         * @param arguments the argument list to provide to the target
         * @return AZ::Outcome with the command result on success
         */
        AZ::Outcome<QString, QString> CreateDesktopShortcut(const QString& filename, const QString& targetPath, const QStringList& arguments);
        
        AZ::IO::FixedMaxPath GetEditorDirectory();

    } // namespace ProjectUtils
} // namespace O3DE::ProjectManager
