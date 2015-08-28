TEMPLATE = subdirs

SUBDIRS += \
    Project4interview \
    Project4interviewLib \
    ProjectTestSuite


Project4interview.depends = Project4interviewLib
ProjectTestSuite.depends = Project4interviewLib


