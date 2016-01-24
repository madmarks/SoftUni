import yaml
from .loader import Loader


class YAMLLoader(Loader):

    def __init__(self, filename):
        super().__init__(filename)

    def load(self):
        with open(self.filename) as f:
            input_data = yaml.load(f)
            return input_data
