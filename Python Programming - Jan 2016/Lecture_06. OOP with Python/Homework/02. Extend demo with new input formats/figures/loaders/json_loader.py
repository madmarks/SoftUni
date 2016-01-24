import json
from .loader import Loader


class JSONLoader(Loader):

    def __init__(self, filename):
        super().__init__(filename)

    def load(self):
        with open(self.filename) as f:
            input_data = json.load(f)
            return input_data
