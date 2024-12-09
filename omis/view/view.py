class WindowTemplate:
    def __init__(self):
        pass
class IWindowTemplateSource:
    def __init__(self,):
        self.template:WindowTemplate

class FileWindowTemplateSource(IWindowTemplateSource):
    def __init__(self):
        super().__init__()

class WindowFactory:
    def __init__(self):
        window_template_source=IWindowTemplateSource

    def create(self,data)->WindowTemplate:
        pass

