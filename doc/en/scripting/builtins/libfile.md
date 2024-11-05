# *file* library

Filesystem interaction library.

```python
file.resolve(path: str) -> str
```

Function turns `entry_point:path` (example `user:worlds/house1`) to a regular path. (example `C://Users/user/.voxeng/worlds/house1`)

> [!NOTE]
> The function should be used for debug only. *entry_point:path* notation is required in all **file** functions.

Resulting path is not canonical and may be relative.

```python
file.read(path: str) -> str
```

Read whole text file.

```python
file.read_bytes(path: str) -> array of integers
```

Read file into bytes array.

```python
file.write(path: str, text: str) -> nil
```

Overwrite text file.

```python
file.write_bytes(path: str, data: array of integers)
```

Overwrite binary file with bytes array.

```python
file.length(path: str) -> int
```

Get file length (bytes) or 0.

```python
file.exists(path: str) -> bool
```

Check if file or directory exist.

```python
file.isfile(path: str) -> bool
```

Check if the path points to a file.

```python
file.isdir(path: str) -> bool
```

Check if the path points to a directory.

```python
file.mkdir(path: str) -> bool
```

Create directory. Returns true if new directory created

```python
file.mkdirs(path: str) -> bool
```

Create directories chain. Returns true if new directory created.

```python
file.list(path: str) -> array of strings
```

Returns a list of files and directories in the specified.

```python
file.list_all_res(path: str) -> array of strings
```

Returns a list of files and directories in the specified one without specifying an entry point.

```python
file.find(path: str) -> str
```

Searches for a file from the last pack to res. The path is specified without a prefix. Returns the path with the required prefix. If the file is not found, returns nil.

```python
file.remove(path: str) -> bool
```

Deletes a file. Returns **true** if the file exists. Throws an exception on access violation.

```python
file.remove_tree(path: str) -> int
```

Recursively deletes files. Returns the number of files deleted.

```python
file.read_combined_list(path: str) -> array
```

Combines arrays from JSON files of different packs.

```python
file.read_combined_object(path: str) -> array
```

Combines objects from JSON files of different packs.