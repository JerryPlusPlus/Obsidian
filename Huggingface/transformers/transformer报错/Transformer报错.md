```
No model was supplied, defaulted to distilbert/distilbert-base-uncased-finetuned-sst-2-english and revision af0f99b (https://huggingface.co/distilbert/distilbert-base-uncased-finetuned-sst-2-english).
Using a pipeline without specifying a model name and revision in production is not recommended.
D:\Anaconda\tfgpu2.6-py3.9\lib\site-packages\huggingface_hub\file_download.py:1132: FutureWarning: `resume_download` is deprecated and will be removed in version 1.0.0. Downloads always resume when possible. If you want to force a new download, use `force_download=True`.
  warnings.warn(
D:\Anaconda\tfgpu2.6-py3.9\lib\site-packages\huggingface_hub\file_download.py:157: UserWarning: `huggingface_hub` cache-system uses symlinks by default to efficiently store duplicated files but your machine does not support them in C:\Users\geniu\.cache\huggingface\hub\models--distilbert--distilbert-base-uncased-finetuned-sst-2-english. Caching files will still work but in a degraded version that might require more space on your disk. This warning can be disabled by setting the `HF_HUB_DISABLE_SYMLINKS_WARNING` environment variable. For more details, see https://huggingface.co/docs/huggingface_hub/how-to-cache#limitations.
To support symlinks on Windows, you either need to activate Developer Mode or to run Python as an administrator. In order to see activate developer mode, see this article: https://docs.microsoft.com/en-us/windows/apps/get-started/enable-your-device-for-development
  warnings.warn(message)
Press any key to continue . . .
```

- 没有指定模型和版本，因此默认使用了 `distilbert/distilbert-base-uncased-finetuned-sst-2-english`。
```python
from transformers import pipeline
classifier = pipeline("sentiment-analysis")#此处没有指定模型
classifier("We are very happy to show you the 🤗 Transformers library.")
[{'label': 'POSITIVE', 'score': 0.9998}]
# 使用指定模型和版本
model_name = "distilbert-base-uncased-finetuned-sst-2-english"
classifier = pipeline('sentiment-analysis', model=model_name)
```


D:\Anaconda\tf2gpu\lib\site-packages\transformers\deepspeed.py:23: FutureWarning: transformers.deepspeed module is deprecated and will be removed in a future version. Please import deepspeed modules directly from transformers.integrations
  warnings.warn(
Traceback (most recent call last):
  File "D:\Anaconda\tf2gpu\lib\site-packages\transformers\optimization_tf.py", line 25, in <module>
    from tf_keras.optimizers.legacy import Adam
ModuleNotFoundError: No module named 'tf_keras'

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "D:\Anaconda\tf2gpu\lib\site-packages\transformers\utils\import_utils.py", line 1510, in _get_module
    return importlib.import_module("." + module_name, self.__name__)
  File "D:\Anaconda\tf2gpu\lib\importlib\__init__.py", line 127, in import_module
    return _bootstrap._gcd_import(name[level:], package, level)
  File "<frozen importlib._bootstrap>", line 1030, in _gcd_import
  File "<frozen importlib._bootstrap>", line 1007, in _find_and_load
  File "<frozen importlib._bootstrap>", line 986, in _find_and_load_unlocked
  File "<frozen importlib._bootstrap>", line 680, in _load_unlocked
  File "<frozen importlib._bootstrap_external>", line 850, in exec_module
  File "<frozen importlib._bootstrap>", line 228, in _call_with_frames_removed
  File "D:\Anaconda\tf2gpu\lib\site-packages\transformers\optimization_tf.py", line 27, in <module>
    from tensorflow.keras.optimizers.legacy import Adam
ModuleNotFoundError: No module named 'tensorflow.keras.optimizers.legacy'

The above exception was the direct cause of the following exception:

Traceback (most recent call last):
  File "D:\Anaconda\tf2gpu\lib\runpy.py", line 197, in _run_module_as_main
    return _run_code(code, main_globals, None,
  File "D:\Anaconda\tf2gpu\lib\runpy.py", line 87, in _run_code
    exec(code, run_globals)
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy\__main__.py", line 39, in <module>
    cli.main()
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy/..\debugpy\server\cli.py", line 430, in main
    run()
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy/..\debugpy\server\cli.py", line 284, in run_file
    runpy.run_path(target, run_name="__main__")
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy\_vendored\pydevd\_pydevd_bundle\pydevd_runpy.py", line 321, in run_path
    return _run_module_code(code, init_globals, run_name,
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy\_vendored\pydevd\_pydevd_bundle\pydevd_runpy.py", line 135, in _run_module_code
    _run_code(code, mod_globals, init_globals,
  File "c:\program files\microsoft visual studio\2022\enterprise\common7\ide\extensions\microsoft\python\core\debugpy\_vendored\pydevd\_pydevd_bundle\pydevd_runpy.py", line 124, in _run_code
    exec(code, run_globals)
  File "F:\Python\Transformers\Transformers\main.py", line 2, in <module>
    from transformers import *
  File "<frozen importlib._bootstrap>", line 1053, in _handle_fromlist
  File "<frozen importlib._bootstrap>", line 1055, in _handle_fromlist
  File "D:\Anaconda\tf2gpu\lib\site-packages\transformers\utils\import_utils.py", line 1498, in __getattr__
    value = self._get_module(name)
  File "D:\Anaconda\tf2gpu\lib\site-packages\transformers\utils\import_utils.py", line 1512, in _get_module
    raise RuntimeError(
RuntimeError: Failed to import transformers.optimization_tf because of the following error (look up to see its traceback):
No module named 'tensorflow.keras.optimizers.legacy'
Press any key to continue . . .

```